
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); //Connect HC-06. Use your (TX, RX) settings

void setup()  
{
  Serial.begin(9600);
  Serial.println("Hello!");

  BTSerial.begin(9600);  // set the data rate for the BT port
  pinMode(13, OUTPUT);
  
}

bool light=false;

void loop()
{
  int incomingByte;
  // BT –> Data –> Serial
  if (BTSerial.available()) {
    incomingByte = BTSerial.read();
    Serial.write(incomingByte);

    if(incomingByte == '1') light=true;
    if(incomingByte == '0') light=false;
  }

  if(light)
  {
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);
    delay(50);
  }

  
  // Serial –> Data –> BT
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
