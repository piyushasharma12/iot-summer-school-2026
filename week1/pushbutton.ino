int buttonState = 0;
const int LED = 3;

void Setup()
{
 pinMode(2,INPUT);
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 
}

void loop()
{
  buttonState=digitalRead(2);
  //for()
  while(buttonState ==LOW){
    digitalWrite(LED,LOW);
  delay(10);
}


