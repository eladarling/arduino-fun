/*For the 12v stepper motor we're using, the motor wires should be on the board/driver in this order:
 * Motor Power
 * Motor Ground
 * Green
 * Gray
 * Yellow
 * Red
 * 5V
 * Ground
 */


const int stepPin = 3;
const int dirPin = 4;
const int sleepPin = 5;
const int resetPin = 6;
/*const int ms1 = 11;   //uncomment these for fractional steps
const int ms2 = 10;
const int ms3 = 9;
*/

void setup() {
  Serial.begin(9600);
  
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(resetPin,OUTPUT);
  pinMode(sleepPin,OUTPUT);
/*  pinMode(ms1,OUTPUT);
  pinMode(ms2,OUTPUT);
  pinMode(ms3,OUTPUT);
 
  digitalWrite(ms1,HIGH);   //uncomment for half steps
  digitalWrite(ms2,LOW);
  digitalWrite(ms3,LOW);
  */

  digitalWrite(dirPin,LOW);
  digitalWrite(sleepPin,LOW);    //this is to eliminate the high pitched sound of the motor at rest
  digitalWrite(resetPin,LOW); 
  Serial.println("Ok!"); 
  delay(1000);
}

void ReadCommandFromSerial() {
  int input = Serial.parseInt();
  if (input == 0)
    return;
  if (input == 1){
    
    delay(50);
    digitalWrite(sleepPin,HIGH);    //turn off sleep/reset; this may result in noise
    digitalWrite(resetPin,HIGH);
    delay(50); 
    for(int x = 0; x < 10; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(5000);      //if increased by ^10, problems arise and the motor skips/stalls
      digitalWrite(stepPin,LOW);
      delayMicroseconds(10000);
    }
    Serial.println ("Good boy, Gonzo!");   
    delayMicroseconds(50000);
  }
  digitalWrite(sleepPin,LOW);  //hopefully this will help with motor overheating
  

}
  
void loop() {
  ReadCommandFromSerial();
}

