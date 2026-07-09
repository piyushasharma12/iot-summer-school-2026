const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int button = 7;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(button) == HIGH) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing");

    delay(8000);
    return;
  }

  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  Serial.print(millis());
  Serial.println(" ms : RED");
  delay(5000);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  Serial.print(millis());
  Serial.println(" ms : YELLOW");
  delay(2000);

  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  Serial.print(millis());
  Serial.println(" ms : GREEN");
  delay(4000);

  digitalWrite(greenLED, LOW);
}