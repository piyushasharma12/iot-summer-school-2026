#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const char* ssid = "OnePlus";
const char* password = "12042006";

// Google Apps Script / IFTTT URL
String serverName = "YOUR_WEB_APP_URL";


LiquidCrystal_I2C lcd(0x27, 16, 2);


#define SOIL_PIN      34
#define LDR_PIN       35
#define PUMP_LED      26
#define BUTTON_PIN    25

int soilValue = 0;
int moisturePercent = 0;

int lightValue = 0;

bool rainDetected = false;

bool pumpState = false;

bool manualMode = false;

unsigned long lastManualTime = 0;
unsigned long lastWaterTime = 0;

// 5 minutes
const unsigned long lockoutTime = 300000;


void setup() {

  Serial.begin(115200);

  pinMode(PUMP_LED, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(PUMP_LED, LOW);

  Wire.begin(21,22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Plant Watering");

  lcd.setCursor(0,1);
  lcd.print("Connecting...");

  // WiFi
  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){

    delay(500);
    Serial.print(".");

  }

  Serial.println();
  Serial.println("WiFi Connected");

  lcd.clear();
  lcd.print("WiFi Connected");

  delay(1500);
  lcd.clear();
}


void loop() {

 
  soilValue = analogRead(SOIL_PIN);

  moisturePercent = map(
      soilValue,
      4095,
      0,
      0,
      100
  );

  moisturePercent = constrain(
      moisturePercent,
      0,
      100
  );

  
  lightValue = analogRead(LDR_PIN);

  if(lightValue < 1800)
      rainDetected = true;
  else
      rainDetected = false;

 
  if(digitalRead(BUTTON_PIN)==LOW){

      if(millis()-lastManualTime > lockoutTime){

          manualMode = true;

          lastManualTime = millis();

          lastWaterTime = millis();

          digitalWrite(PUMP_LED,HIGH);

          pumpState = true;

          Serial.println("Manual Watering Started");

      }

      else{

          Serial.println("Manual Lockout Active");

      }

      delay(300);

  }

  

  if(!manualMode){

      if(moisturePercent < 30){

          if(!rainDetected){

              digitalWrite(PUMP_LED,HIGH);

              pumpState = true;

              lastWaterTime = millis();

          }

          else{

              digitalWrite(PUMP_LED,LOW);

              pumpState = false;

          }

      }

      else{

          digitalWrite(PUMP_LED,LOW);

          pumpState = false;

      }

  }


  if(manualMode){

      if(millis()-lastManualTime>10000){

          digitalWrite(PUMP_LED,LOW);

          pumpState=false;

          manualMode=false;

      }

  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("M:");
  lcd.print(moisturePercent);
  lcd.print("% ");

  if (manualMode)
    lcd.print("MAN");
  else
    lcd.print("AUTO");

  lcd.setCursor(0, 1);

  if (pumpState)
    lcd.print("Pump:ON ");
  else
    lcd.print("Pump:OFF");

  lcd.print(" ");

  lcd.print(lastWaterTime / 1000);
  lcd.print("s");


  Serial.println("--------------------------");

  Serial.print("Moisture : ");
  Serial.print(moisturePercent);
  Serial.println("%");

  Serial.print("LDR Value : ");
  Serial.println(lightValue);

  Serial.print("Rain : ");
  if (rainDetected)
    Serial.println("YES");
  else
    Serial.println("NO");

  Serial.print("Mode : ");
  if (manualMode)
    Serial.println("MANUAL");
  else
    Serial.println("AUTO");

  Serial.print("Pump : ");
  if (pumpState)
    Serial.println("ON");
  else
    Serial.println("OFF");

  Serial.print("Last Watered : ");
  Serial.print(lastWaterTime / 1000);
  Serial.println(" sec");

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = serverName +
                 "?moisture=" + String(moisturePercent) +
                 "&light=" + String(lightValue) +
                 "&pump=" + String(pumpState) +
                 "&mode=" + String(manualMode);

    http.begin(url);

    int httpResponseCode = http.GET();

    Serial.print("HTTP Response: ");
    Serial.println(httpResponseCode);

    http.end();
  }

  else {

    Serial.println("WiFi Disconnected");

  }

  delay(5000);

}