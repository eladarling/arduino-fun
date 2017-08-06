int trigPin = 5;    //Trig 
int echoPin = 3;    //Echo 

long duration, cm, inches;    //define distance variables
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);     //clear the trigPin to ensure clean HIGH pulse

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     //set trigPin to HIGH state so itemits a pulse for 10 microseconds, which is the minimum for these sensors
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;     // convert the time into a distance
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
