//----------------------------------------
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include<SoftwareSerial.h>
SoftwareSerial Myserial(13, 15); //Red wire D2 & Black wire D1
//----------------------------------------
#define ON_Board_LED 2  //--> Defining an On Board LED, used for indicators when the process of connecting to a wifi router
//----------------------------------------SSID and Password of your WiFi router.
const char* ssid = "Redmi Note 11"; //--> Your wifi name or SSID.
const char* password = "12345678"; //--> Your wifi password.
//----------------------------------------

//----------------------------------------Host & httpsPort
const char* host = "script.google.com";
const int httpsPort = 443;
//----------------------------------------

//----------------------------------------
int h, d, n;
String url;
String t;
String stringData;
char someDataFeed[10];
char keyword[] = "S";
//bool Myflag = false;
//----------------------------------------

WiFiClientSecure client; //--> Create a WiFiClientSecure object.

String GAS_ID = "AKfycbwUHWs_qAo6A_Jzl6XnSK1Dvc1tj88WF-wtEay7sDB7uZsdbyxPD7V-mcdju-_9hlE"; //--> spreadsheet script ID

//============================================================================== void setup
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // initialize UART with baud rate of 9600 bps
  Myserial.begin(9600);
  delay(500);

  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");

  pinMode(ON_Board_LED, OUTPUT); //--> On Board LED port Direction output
  digitalWrite(ON_Board_LED, HIGH); //--> Turn off Led On Board

  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    //----------------------------------------Make the On Board Flashing LED on the process of connecting to the wifi router.
    digitalWrite(ON_Board_LED, LOW);
    delay(250);
    digitalWrite(ON_Board_LED, HIGH);
    delay(250);
    //----------------------------------------
  }
  //----------------------------------------
  digitalWrite(ON_Board_LED, HIGH); //--> Turn off the On Board LED when it is connected to the wifi router.
  //----------------------------------------If successfully connected to the wifi router, the IP Address that will be visited is displayed in the serial monitor
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  //----------------------------------------

  client.setInsecure();
}
//==============================================================================
//============================================================================== void loop
void loop() {
  stringData = Myserial.readString();
  stringData.toCharArray(someDataFeed, 10);
  char *pointerToFoundData = strstr(someDataFeed, keyword);//go find keyword
  if (pointerToFoundData != NULL) { //found it
    int positionInString = pointerToFoundData - someDataFeed;
    //Myflag = true;
    Serial.print("Keyword Starts at ");
    Serial.println(positionInString);

    //now strip out keyword and junk
    char goodData[5];
    strncpy(goodData, &someDataFeed[positionInString + strlen(keyword)], sizeof(goodData));
    goodData[5] = NULL;
    Serial.println(goodData);
    t = String(goodData);
  }
  sendData(stringData);
  //else {
  //  Serial.println("NO KEYWORD");
//  //}
//  if (Myflag == true)
//  {
//    sendData(t); //--> Calls the sendData Subroutine
//    Myflag = false;
//  }


}
//==============================================================================
//============================================================================== 
// Subroutine for sending data to Google Sheets
void sendData(String t) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print(n);

  //----------------------------------------Connect to Google host
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  //----------------------------------------

  //----------------------------------------Processing data and sending data

  String string_Weight =  String(t);
  //String string_GrossWeight =  String(hum, DEC);
  url = "/macros/s/" + GAS_ID + "/exec?weight=" + string_Weight;



  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  //----------------------------------------

  //----------------------------------------Checking whether the data was sent successfully or not
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.print("reply was : ");
  Serial.println(line);
  Serial.println("closing connection");
  Serial.println("==========");
  Serial.println();
  //----------------------------------------
}
//==============================================================================
