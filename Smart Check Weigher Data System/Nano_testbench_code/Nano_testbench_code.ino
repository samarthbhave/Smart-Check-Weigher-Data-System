void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("00S0251400025140000");
  delay(1500);
  Serial.println("00S0502800050280000");
  delay(1500);
  Serial.println("00S0754200075420000");
  delay(1500);
  Serial.println("00S0100560100560000");
  delay(1500);
  Serial.println("00S0125700125700000");
  delay(1500);      
  Serial.println("00S0150850150850000");
  delay(1500);   
  Serial.println("00S0175100175100000");
  delay(1500);      
}
