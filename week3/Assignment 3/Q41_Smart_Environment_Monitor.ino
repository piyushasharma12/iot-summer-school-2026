#include <WiFi.h>
#include <DHT.h>

// ---------------- PINS ----------------
#define DHTPIN 4
#define DHTTYPE DHT22

#define MQ2_PIN 34
#define LDR_PIN 35

#define HEATER_LED 25
#define AC_LED 26
#define ALERT_LED 27
#define BUZZER 13

// ---------------- SENSOR ----------------
DHT dht(DHTPIN, DHTTYPE);

// ---------------- THRESHOLDS ----------------
float TEMP_LOW = 22.0;
float TEMP_HIGH = 28.0;

int GAS_THRESHOLD = 1800;
int LIGHT_THRESHOLD = 2000;

void setup() {
  Serial.begin(115200);

  dht.begin();

  pinMode(MQ2_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);

  pinMode(HEATER_LED, OUTPUT);
  pinMode(AC_LED, OUTPUT);
  pinMode(ALERT_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("SMART ENVIRONMENT MONITOR STARTED");
}

void loop() {

  // -------- Read sensors --------
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int gasValue = analogRead(MQ2_PIN);
  int lightValue = analogRead(LDR_PIN);

  // -------- Print values --------
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Hum: ");
  Serial.print(hum);

  Serial.print(" | Gas: ");
  Serial.print(gasValue);

  Serial.print(" | Light: ");
  Serial.println(lightValue);

  // -------- Safety check --------
  bool gasLeak = gasValue > GAS_THRESHOLD;

  if (gasLeak) {
    digitalWrite(ALERT_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    Serial.println(" GAS LEAK DETECTED!");
  } else {
    digitalWrite(ALERT_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  // -------- Temperature control --------
  if (temp < TEMP_LOW) {
    digitalWrite(HEATER_LED, HIGH);
    digitalWrite(AC_LED, LOW);
    Serial.println("HEATER ON ❄");
  }
  else if (temp > TEMP_HIGH) {
    digitalWrite(AC_LED, HIGH);
    digitalWrite(HEATER_LED, LOW);
    Serial.println("AC ON ");
  }
  else {
    digitalWrite(AC_LED, LOW);
    digitalWrite(HEATER_LED, LOW);
  }

  delay(2000);
}
