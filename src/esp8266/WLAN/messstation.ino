#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define SSID "the_ssid"
#define PW "the_password"
#define THRESHOLD 2
volatile int lastMeasure;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  // For the initial value
  lastMeasure = analogRead(A0);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  int a = analogRead(A0);
  if(a > (lastMeasure + THRESHOLD) || a < (lastMeasure - THRESHOLD)) {
    HTTPClient http;
    http.begin("http://192.168.0.2:3001/"); // TODO: port und IP hardcoden ist ziemlich schlecht. Besser wäre wenn man es z.b. über Serial immer wieder ändern könnte
    http.addHeader("Content-Type", "application/json");
    String s = "{\"temperature\": "; //TODO: das manuelle zusammenbasteln der json ist schlecht. Besser eine Library dafür suchen
    s.concat(lastMeasure);
    s.concat("}");
    int code = http.POST(s);
    http.end();
  }
  lastMeasure = a;
  delay(5000);
}