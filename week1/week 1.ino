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



const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

const int buttonPin = 2;

unsigned long startTime;
unsigned long reactionTime;


void setup() {

pinMode(redLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);

pinMode(buttonPin, INPUT_PULLUP);

Serial.begin(9600);

randomSeed(analogRead(A0));

Serial.println("Reaction Time Game");
}


void loop() {


digitalWrite(redLED,LOW);
digitalWrite(yellowLED,LOW);
digitalWrite(greenLED,LOW);


delay(2000);


// Random LED blinking

for(int i=0;i<10;i++)
{

int led=random(8,11);
int time=random(200,1000);


digitalWrite(led,HIGH);
delay(time);
digitalWrite(led,LOW);

delay(random(100,500));

}


// Green signal

Serial.println("GO!");

digitalWrite(greenLED,HIGH);


startTime=millis();


// wait for button

while(digitalRead(buttonPin)==HIGH)
{

}


reactionTime=millis()-startTime;


digitalWrite(greenLED,LOW);


Serial.print("Reaction Time = ");
Serial.print(reactionTime);
Serial.println(" ms");


delay(3000);

}


#include <Servo.h>
Servo myServo;

void setup() {
  myServo.attach(6);
}

void loop() {
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);
}



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