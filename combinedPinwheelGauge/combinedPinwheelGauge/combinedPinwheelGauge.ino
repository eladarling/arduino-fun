#include <Servo.h>

Servo servofriend;

const int servoAttachPin = 6;
const int motorPin = 11;

int speed = 0;
int pos = 90;
int where = -1;

void setup() 
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  servofriend.attach(servoAttachPin);
  Serial.println ("SHOW ME WHAT YOU GOT, COWBOY");
}

void ReadCommandFromSerial()
{
  char spin = Serial.read();
  switch (spin)
  {
    case '0':     //stop motor
      speed = 0;
      analogWrite(motorPin, speed);
      Serial.println ("hold yer horses, cowboy!");
      Serial.print ("speed = ");
      Serial.println (speed);
      break;
    case '1':     //speed up motor
      speed = speed + 20;
      if (speed > 240)
        speed = 240;
      analogWrite (motorPin, speed);
      Serial.println ("yeehaw!");
      Serial.print ("speed = ");
      Serial.println (speed);
      break;
    case '2':     //slow down motor
      speed = speed - 20;
      analogWrite (motorPin, speed);
      Serial.println ("whoa, there!");
      Serial.print ("speed = ");
      Serial.println (speed);
      break;
    case '3':     //upvote servo: move servo right
      pos = pos + 10;
      if (pos > 190)
        pos = 190;
      servofriend.write(pos);
      where = servofriend.read();
      Serial.println ("I LIKE WHAT YOU GOT");
      Serial.print ("pos = ");
      Serial.println (where);
      break;
    case '4':     //downvote servo: move servo left 
      pos = pos - 10;
      if (pos < 0)
        pos = 0;
      servofriend.write(pos);
      where = servofriend.read();
      Serial.println ("BOO. DISQUALIFIED.");
      Serial.print ("pos = ");
      Serial.println (where);
      break;   
  }
}

void loop() {
  ReadCommandFromSerial();
}
