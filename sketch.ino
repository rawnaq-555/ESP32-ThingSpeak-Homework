
#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

// WiFi Settings
const char* WIFI_Name = "Wokwi-GUEST";
const char* WIFI_Pass = "";

// ThingSpeak Settings
const unsigned long channelNumber = 3549803;
const char* apiKey = "2IY74TPCJ387P0TN";

WiFiClient clientObject;

// DHT22 Sensor
#define DHTPIN 15
#define DHTTYPE DHT22

DHT sensorDHT(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  sensorDHT.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_Name, WIFI_Pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Status: Not Connected");
    delay(1000);
  }

  Serial.println("Status: Connected");
  Serial.println("University ID: 12401585");

  ThingSpeak.begin(clientObject);
}
  
void loop() {

  float temperature = sensorDHT.readTemperature();
  float humidity = sensorDHT.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Sensor Reading Failed");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int stat = ThingSpeak.writeFields(channelNumber, apiKey);

  if (stat == 200) {
    Serial.println("Data Sent to ThingSpeak");
  } else {
    Serial.print("ThingSpeak Error: ");
    Serial.println(stat);
  }

  delay(20000);
}
