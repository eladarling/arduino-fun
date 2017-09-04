
int motorPin = 11;
int speed = 0;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
} 

void ReadCommandFromSerial()
{
  char spin = Serial.read();
  switch (spin)
  {
    case 'ai':
      speed = 0;
      analogWrite(motorPin, speed);
      Serial.println ("hold yer horses, cowboy!");
      Serial.println (speed);
      break;
    case 'bi':
      speed = speed + 20;
      if (speed > 240)
        speed = 240;
      analogWrite(motorPin, speed);
      Serial.println ("yeehaw!");
      Serial.println (speed);
      break;
    case 'ci':
      speed = speed - 20;
        if (speed < 0)
        speed = 0;
      analogWrite(motorPin, speed); 
      Serial.println ("whoa there!");
      Serial.println (speed);
      break;
   }
}
 
void loop() 
{ 
  ReadCommandFromSerial();
}
    
