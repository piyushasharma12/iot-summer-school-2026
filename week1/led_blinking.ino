author piyusha sharma
IOT027
Summer School 26

int LDR = A0;
int LED = 13;

void setup()
{
  pinMode(LED, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(LDR);

  Serial.println(value);

  if(value < 300)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  delay(500);
}
