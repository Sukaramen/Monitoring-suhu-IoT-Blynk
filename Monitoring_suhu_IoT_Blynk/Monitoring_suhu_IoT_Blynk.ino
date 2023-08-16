#define BLYNK_TEMPLATE_ID "************"
#define BLYNK_TEMPLATE_NAME "************"
#define BLYNK_AUTH_TOKEN "************"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "************";
char ssid[] = "************";
char pass[] = "************";
#define DHTTYPE DHT11
#define DHTPIN D2
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("% Temperature: ");
  Serial.print(t);
  Serial.println("C ");
  Serial.print("% Kelembaban: ");
  Serial.print(h);
  Serial.println("% ");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h); 
}
void setup() {
  Serial.begin(115200); 
  Blynk.begin(auth, ssid, pass); 
  dht.begin();
  timer.setInterval(1000L, sendSensor); 
}

void loop() {
  Blynk.run();
  timer.run(); 
}
