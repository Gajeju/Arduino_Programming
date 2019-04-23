#include <SoftwareSerial.h>
int Tx = 2;
int Rx = 3;
SoftwareSerial mySerial (Tx, Rx);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if(Serial.available()){
    mySerial.write(Serial.read());
  } 
}
