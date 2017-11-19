#include <Servo.h>  //include Servo library

Servo lilguy;   //declare the servo. He's a lil guy.

const int servoPin = 9; //attach the servo to pin9

int pos = 1465;  //i am guessing we're going to start by establishing the speed followed by a delay



void setup() {
  Serial.begin(9600);
  lilguy.attach(servoPin);
  Serial.println("Ready!");
  lilguy.write(pos);
}

void ReadCommandFromSerial()
{
  char rotate = Serial.read();
  switch(rotate)
  {
    case '0':
    {pos = 1465;
     lilguy.writeMicroseconds(pos);
     Serial.println ("stopped");
     Serial.println (pos);
    }
    break;
    case '1':
    {pos = pos + 90;
     lilguy.writeMicroseconds(pos);
     Serial.println ("plus");
     Serial.println (pos);
    }
    break;
    case '2':
    {pos = pos - 90;
     lilguy.writeMicroseconds(pos);
     Serial.println ("minus");
     Serial.println (pos);
    }
    break;
  }
  delay(150);
}
void loop() {
 ReadCommandFromSerial();
}
