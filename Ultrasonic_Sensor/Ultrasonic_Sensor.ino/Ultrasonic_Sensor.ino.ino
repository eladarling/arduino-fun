#include <NewPing.h>
 
#define TRIGGER_PIN  A5
#define ECHO_PIN     A4
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
   int dist = sonar.ping_median(5); //median of 5 values
   dist = sonar.convert_cm(dist); //convert that to cm,
   Serial.print("Distance: ");
   Serial.print(dist); // //print value to screen so we can see it.
   Serial.println(" cm");
}


