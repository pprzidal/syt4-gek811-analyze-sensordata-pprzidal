#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

//TODO: vllt. einen WiFi Settings seperat vom Sketch

#define DEBUG
#define SSID
#define PW
#define THRESHOLD 2 // TODO: immer neukompilieren und flashen wenn man den Wert ändern will ist blöd. Könnte man vllt. auch über Serial + EEPRO machen
volatile int lastMeasure;

void setup() {
  Serial.begin(9600);
  WiFi.begin(SSID, PW);
  #ifdef DEBUG
  Serial.println(F("Connecting"));
  #endif
  // For the initial value
  lastMeasure = analogRead(A0);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  #ifdef DEBUG
  Serial.println(F("Finished connecting"));
  #endif
}

void loop() {
  #ifdef DEBUG
  Serial.println(F("New Loop Itaration"));
  #endif
  int a = analogRead(A0);
  if (a > (lastMeasure + THRESHOLD) || a < (lastMeasure - THRESHOLD)) {
    HTTPClient http;
    http.begin(F("http://192.168.0.2:3001/")); // TODO: port und IP hardcoden ist ziemlich schlecht. Besser wäre wenn man es z.b. über Serial immer wieder ändern könnte
    http.addHeader(F("Content-Type"), F("application/json"));
    String s = F("{\"temperature\": "); //TODO: das manuelle zusammenbasteln der json ist schlecht. Besser eine Library dafür suchen
    s.concat((((lastMeasure * 3.3 / 1023.0) - 0.5) * 100));
    s.concat(F("}"));
    int response = http.POST(s);
    http.end();
    lastMeasure = a;
    #ifdef DEBUG
    Serial.print(F("Send a POST "));
    Serial.println(response);
    #endif
  }
  delay(5000);
}