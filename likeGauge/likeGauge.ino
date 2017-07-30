#include <Servo.h>

Servo servofriend;

const int servoAttachPin = 6;
int pos = 90;
  
void setup() 
{
  servofriend.attach(servoAttachPin);
  Serial.begin(9600);
  Serial.println ("SHOW ME WHAT YOU GOT");    //lets you know things have initialized
}

void ReadCommandFromSerial()
{
  int where = -1;   //so we know if shit isn't working

  char twist = Serial.read(); //I'm not actually sure if this is necessary?

  
  switch (twist)
  {
    case '1':     //if we get an upvote, she moves 10 degrees to the right
      pos = pos + 10;
     // if (pos > 180)
     //   pos = 180;
      servofriend.write(pos);
      where = servofriend.read();
      Serial.println ("I LIKE WHAT YOU GOT");
      Serial.println (where);
      break;
    case '2':     //if we get a downvote, she moves 10 degrees to the left
      pos = pos - 10;
     // if (pos < 0)
     //  pos = 0;
      servofriend.write(pos);
      where = servofriend.read();
      Serial.println ("BOO. DISQUALIFIED.");
      Serial.println (where);
      break;
  }
}

/* For some reason the servo starts at 90 and wont go above 100 or below 80 now.
 *  When initializing, it doesn't always fully or correctly print the intro line (SHOW ME WHAT YOU GOT)
 *  Possibly related, when I have it plugged in for a few minutes, the attached motor starts spinning wildly. Disconnecting the motor didn't help.
 *  update: this was because I declared int pos in the function so every time it completed, the pos was reset to 90.
 */


void loop() {
  ReadCommandFromSerial();
}
