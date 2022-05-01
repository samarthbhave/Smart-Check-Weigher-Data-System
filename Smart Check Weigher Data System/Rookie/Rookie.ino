#include<SoftwareSerial.h>
SoftwareSerial Myserial(13,15); //Red wire D2 & Black wire D1
String stringData;
char someDataFeed[10];

char keyword[] = "S";
void setup() {
  Serial.begin(9600);   // initialize UART with baud rate of 9600 bps
//  Myserial.begin(9600);
}

void loop() {
  stringData = Serial.readString();
  stringData.toCharArray(someDataFeed, 10);
  char *pointerToFoundData = strstr(someDataFeed, keyword);//go find keyword
  if (pointerToFoundData != NULL) { //found it
    int positionInString = pointerToFoundData - someDataFeed;
    Serial.print("Keyword Starts at ");
    Serial.println(positionInString);

    //now strip out keyword and junk
    char goodData[6];
    strncpy(goodData, &someDataFeed[positionInString + strlen(keyword)], sizeof(goodData));
    goodData[6] = NULL;
    Serial.println(goodData);
  } else {
    Serial.println("NO KEYWORD");
  }
  

}
