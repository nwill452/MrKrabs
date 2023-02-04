int motor2[] = {2, 3};
int motor1[] = {4, 5};

#define echoPin 8
#define trigPin 9

/***
// Turn Start Time
float  turnStartTime;
// Turn Duration
float turnDuration;
// Turn Current Time
float currentTurnTime;

//long duration;
// Sup
int distance;
**/
#include "WheelController.h"
#include "UltraSound.h"

UltraSound  soundSensor(8,9)
WheelController  Controller(motor1,motor2);

void setup() {
  /**
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  **/
  Serial.begin(9600);
  
 
}

void loop() {
  

 
}




int getDistance()
{
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  return distance;
}



int distanceRemoveError(int samples)
{
   int avg = 0;
   for( int i = 0; i < samples; i++  )
   {
       avg += getDistance();
   }

   return avg/samples ;  
}
