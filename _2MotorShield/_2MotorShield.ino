#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600);
  Serial.println("Lets Go!");
  AFMS.begin();

 /* rightMotor->setSpeed(150);
  leftMotor->setSpeed(150);
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);*/
}

void loop() {

  /*rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);  
  rightMotor->setSpeed(150);
  leftMotor->setSpeed(150);
  delay (1000);
  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);  
  delay (1000);*/
  Serial.println("backward");
  rightMotor->run(BACKWARD);
  rightMotor->setSpeed(150);
  leftMotor->run(BACKWARD); 
  leftMotor->setSpeed(150);
  
  delay (1000);
  
  Serial.println("forward");
  rightMotor->run(FORWARD);
  rightMotor->setSpeed(150);
  leftMotor->run(FORWARD);  
  leftMotor->setSpeed(150);

  delay (1000);

  Serial.println("stop");
  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);

  delay (1000);
}
