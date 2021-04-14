#include<SoftwareSerial.h>

#define THRESHOLD 2
volatile int lastMeasure;
SoftwareSerial mySerial(D7, D8);

void setup() {
  pinMode(D7, INPUT);
  pinMode(D8, OUTPUT);
  mySerial.begin(115200);
  // For the initial value
  lastMeasure = analogRead(A0);
  mySerial.println((((lastMeasure * 3.3 / 1023.0) - 0.5) * 100));
}

void loop() {
  int a = analogRead(A0);
  if(a > (lastMeasure + THRESHOLD) || a < (lastMeasure - THRESHOLD)) mySerial.println((((a * 3.3 / 1023.0) - 0.5) * 100));
  lastMeasure = a;
  delay(5000);
}
