#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include "config.h"

#define DHTPIN 33
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  dht.begin();

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected Successfully!");
  Serial.println();

  // OpenWeatherMap API URL
  String url =
    "http://api.openweathermap.org/data/2.5/weather?q=" +
    String(CITY) +
    "&appid=" +
    String(API_KEY) +
    "&units=metric";

  HTTPClient http;

  http.begin(url);

  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {

    String payload = http.getString();

    DynamicJsonDocument doc(2048);

    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
      Serial.println("JSON Parsing Failed!");
      http.end();
      return;
    }

    // API Data
    String city = doc["name"];
    float apiTemp = doc["main"]["temp"];
    int apiHumidity = doc["main"]["humidity"];
    String weather = doc["weather"][0]["description"];

    // Local Sensor Data
    float localTemp = dht.readTemperature();
    float localHumidity = dht.readHumidity();

    if (isnan(localTemp) || isnan(localHumidity)) {
      Serial.println("Failed to read DHT11 Sensor!");
      http.end();
      return;
    }

    Serial.println("----------------------------------------");
    Serial.println(" OpenWeatherMap Weather Report");
    Serial.println("----------------------------------------");

    Serial.print("City Name              : ");
    Serial.println(city);

    Serial.print("API Temperature        : ");
    Serial.print(apiTemp);
    Serial.println(" °C");

    Serial.print("Local Temperature      : ");
    Serial.print(localTemp);
    Serial.println(" °C");

    Serial.print("Temperature Difference : ");
    Serial.print(localTemp - apiTemp);
    Serial.println(" °C");

    Serial.print("API Humidity           : ");
    Serial.print(apiHumidity);
    Serial.println(" %");

    Serial.print("Local Humidity         : ");
    Serial.print(localHumidity);
    Serial.println(" %");

    Serial.print("Humidity Difference    : ");
    Serial.print(localHumidity - apiHumidity);
    Serial.println(" %");

    Serial.print("Weather Description    : ");
    Serial.println(weather);

    Serial.println("----------------------------------------");

  } else {

    Serial.print("HTTP Request Failed. Error Code: ");
    Serial.println(httpResponseCode);

  }

  http.end();
}

void loop() {

}
