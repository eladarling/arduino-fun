#include <Servo.h> //this is a library used to control a servo (for more information see www.arduino.cc for more info)

const int fill = 155; //the position in degrees to fill the hopper
const int empty = 20; //the position in degrees to empty the hopper
const int tolerance = 7; // max feedback measurement error
const int rectifyDegrees = 10; //this is the degree to which the servo moves to correct a jam
const int servoPin = 9; //Servo Signal in pin 9
const int feedbackPin = A0; //feedback cable in A0

Servo mainServo; //declare the main servo

int shouldEmpty = 0; //this is used to switch between fill and empty
int minFeedback;
int maxFeedback;

int getServoPosition()
{
  return map(analogRead(feedbackPin), minFeedback, maxFeedback, empty, fill);
}
  
void calibrate()
{
  mainServo.write(empty);  // Move to the empty position and record the feedback value
  delay(2000); // make sure it has time to get there and settle
  minFeedback = analogRead(feedbackPin);
  
  mainServo.write(fill); // Move to the fill position and record the feedback value 
  delay(2000); // make sure it has time to get there and settle
  maxFeedback = analogRead(feedbackPin); 
}

void setup()
{
  Serial.begin(9600);
  mainServo.attach(servoPin); 
  calibrate();  // calibrate for the fill and empty positions
  Serial.println(minFeedback);
  Serial.println(maxFeedback);
}

void loop()
{
  if (!shouldEmpty) //if shouldEmpty is 0, then send that little cutie to fill
  {
    mainServo.write(fill); //move servo to fill position
    shouldEmpty = 1; //change shouldEmpty to 1 to setup empty
    delay (1000);
    while (getServoPosition() < fill-tolerance)
    {
      mainServo.write(getServoPosition() - rectifyDegrees);
      delay (300);
      mainServo.write(fill);
      delay (800);
      Serial.println ("Ouch! I'm stuck getting full!"); 
    }
  }
  else if (shouldEmpty)
  {
    mainServo.write(empty); //set the servo to empty position
    shouldEmpty = 0; //change shouldEmpty to 0 to setup fill
    delay(1000); //delay while servo sets position
    while (getServoPosition() > empty+tolerance)
    {
      mainServo.write(getServoPosition() + rectifyDegrees);
      delay (300);
      mainServo.write(empty);
      delay (800);
      Serial.println ("Ouch! I'm stuck dropping my load!"); 
    }
  }
  Serial.println(getServoPosition());
}
