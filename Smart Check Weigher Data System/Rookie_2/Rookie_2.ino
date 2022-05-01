#include<SoftwareSerial.h>
SoftwareSerial Myserial(5,4); //Red wire D2 & Black wire D1
int count;
String stringData;
String num_Change;
double Palette_Weight = 90;
double master_value;
double num_one = 0;
double num_two;
char keyword[] = "S";
char someDataFeed[10];


void setup() {
  Serial.begin(9600);   // initialize UART with baud rate of 9600 bps
  Myserial.begin(9600);
}

void loop() 
{
  while(count <= 60)
  {
    stringData = Myserial.readString();
  stringData.toCharArray(someDataFeed, 10);
  char *pointerToFoundData = strstr(someDataFeed, keyword);//go find keyword
  if (pointerToFoundData != NULL) { //found it
    int positionInString = pointerToFoundData - someDataFeed;
    //Serial.print("Keyword Starts at ");
    //Serial.println(positionInString);

    //now strip out keyword and junk
    char goodData[8];
    strncpy(goodData, &someDataFeed[positionInString + strlen(keyword)], sizeof(goodData));
    goodData[8] = NULL;
    goodData[4] = '.';
    num_Change = String(goodData);
    //Serial.println(goodData);
  } else {
    Serial.println("NO KEYWORD");
  }
  master_value = Palette_Weight - num_one;
  Serial.println(master_value);
  master_value = master_value - num_two;
  }
  count += 1;
}
