#include <Servo.h>

Servo servofriend;

const int servoAttachPin = 6;
const int motorPin = 11;      //the motor pin cannot be placed in pins 9 or 10 due to known issues with the servo library disabling PWM on those pins

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
      if (pos > 180)
        pos = 180;
      servofriend.write(pos);
      where = servofriend.read();
      Serial.println ("I LIKE WHAT YOU GOT");
      Serial.print ("pos = ");
      Serial.println (where);
      break;
    case '4':     //downvote servo: move servo left (maybe change this so that at 0 it actually stops at 1 and then after writing the position, reset it to 0 for the sake of motor strain?
      pos = pos - 10;
      if (pos < 10)     //this prevents the servo from overworking itself at the 0 position
        pos = 10;
      servofriend.write(pos);
      where = servofriend.read();
      Serial.println ("BOO. DISQUALIFIED.");
      Serial.print ("pos = ");
      Serial.println (where);
    //  if (pos = 10)      //this is to reset pos to 0 without sending the servo to 0, thus keeping the pos a numeral of 10
      //  pos = 10;       //For some reason, this makes it drop all the way to 10 any time you decrease the angle. 
      break;  
  }
}

void loop() {
  ReadCommandFromSerial();
}
