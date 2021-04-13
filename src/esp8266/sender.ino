#include<SoftwareSerial.h>

SoftwareSerial mySerial(D7, D8);

void setup() {
  pinMode(D7, INPUT);
  pinMode(D8, OUTPUT);
  mySerial.begin(115200);
}

void loop() {
  int a = analogRead(A0);
  mySerial.println((((a * 3.3 / 1023.0) - 0.5) * 100));
  delay(5000);
}
