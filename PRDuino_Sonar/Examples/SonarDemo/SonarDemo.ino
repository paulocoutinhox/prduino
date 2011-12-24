#include <Sonar.h>

int echoPin    = 4; 
int triggerPin = 5; 

PRDuino::Sonar *sonar;

void setup() 
{ 
  Serial.begin (9600); 
  sonar = new PRDuino::Sonar(triggerPin, echoPin);
} 

void loop() 
{
  Serial.print(sonar->getRange(CM)); 
  Serial.println(" cm"); 
  delay(500); 
}
