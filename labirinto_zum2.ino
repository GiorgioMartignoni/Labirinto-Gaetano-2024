#include <Servo.h>

Servo rightServo; 
Servo leftServo; 

//Servo motore
const int leftServoPin = 6; 
const int rightServoPin = 7; 

//Sensori --> trig (invia) azzurro - echo (riceve) bianco 
const int frontTrigPin = 2;
const int frontEchoPin = 3;

const int rightTrigPin = 4;
const int rightEchoPin = 5;

const int leftTrigPin = 23;
const int leftEchoPin = 22;

//Funzione che calcola la distanza --> return float (equivalgono a cm)
float getDistance(float trig, float echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

void avanti(){
  rightServo.write(0);
  leftServo.write(180);
}

void indietro(){
  rightServo.write(135);
  leftServo.write(0);
}

void sinistra(){
  rightServo.write(0);
  leftServo.write(90);
}

void destra(){
  rightServo.write(180);
  leftServo.write(90);
}


void fermo(){
  rightServo.write(90);
  leftServo.write(90);
}


int frontDistance;
int rightDistance;
int leftDistance;

//Setta i valori quando parte il codice
void setup() {
  leftServo.attach(leftServoPin); 
  rightServo.attach(rightServoPin); 
  //pinMode(leftSensorPin, INPUT); 
  //pinMode(middleSensorPin, INPUT); 
  //pinMode(rightSensorPin, INPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(rightEchoPin, INPUT);
  pinMode(leftTrigPin, OUTPUT);
  pinMode(frontTrigPin, OUTPUT);
  pinMode(rightTrigPin, OUTPUT);
  // Serial.begin(9600);
/*
  leftServo.write(90);
  rightServo.write(90);
  */
}

//Parte di codiche che viene eseguita sempre (loop)
void loop() {
  // Leggi le distanze dai sensori di distanza
  frontDistance = getDistance(frontTrigPin, frontEchoPin);
  rightDistance = getDistance(rightTrigPin, rightEchoPin);
  leftDistance = getDistance(leftTrigPin, leftEchoPin);
  
 if(rightDistance>4&&rightDistance<8)
  avanti();

else if(rightDistance<10&&frontDistance<10)
  sinistra();

}
