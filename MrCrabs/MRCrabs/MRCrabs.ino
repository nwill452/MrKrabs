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

UltraSound  soundSensor(8,9);
WheelController  Controller(motor1,motor2);

void setup() {
  /**
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  **/
  Serial.begin(9600);
  
 
}

void loop() {
  
 soundSensor.distanceRemoveError(60);
 
}







