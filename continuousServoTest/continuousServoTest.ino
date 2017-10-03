#include <Servo.h>  //include Servo library

Servo lilguy;   //declare the servo. He's a lil guy.

const int servoPin = 9; //attach the servo to pin9

int speed = 90;  //i am guessing we're going to start by establishing the speed followed by a delay



void setup() {
  Serial.begin(9600);
  lilguy.attach(servoPin);
  Serial.println("Ready!");
}

void ReadCommandFromSerial()
{
  char rotate = Serial.read();
  switch(rotate)
  {
    case '0':
    {speed = 90;
     lilguy.write(speed);
     Serial.println ("stopped");
     Serial.println (speed);
    }
    case '1':
    {speed = speed + 10;
     lilguy.write(speed);
     Serial.println ("plus 10");
     Serial.println (speed);
    }
    case '2':
    {speed = speed - 10;
     lilguy.write(speed);
     Serial.println ("minus 10");
     Serial.println (speed);
    }
  }
}
void loop() {
 ReadCommandFromSerial();
}
