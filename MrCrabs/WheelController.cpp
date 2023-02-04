#include "WheelController.h"

WheelController::WheelController(int wheel1[], int wheel2[])
{
  for (int i = 0; i < 2; i++) {
    motor1[i] = wheel1[i];
    motor2[i] = wheel2[i];
  }

  pinMode(motor1[0], OUTPUT);
  pinMode(motor1[1], OUTPUT);
  pinMode(motor2[0], OUTPUT);
  pinMode(motor2[1], OUTPUT);
}

void  WheelController::MoveForword()
{
      digitalWrite(motor1[0], LOW);
      digitalWrite(motor1[1], HIGH);
  
      digitalWrite(motor2[0], LOW);
      digitalWrite(motor2[1], HIGH);
}
void  WheelController::MoveBackword()
{
      digitalWrite(motor1[0], HIGH);
      digitalWrite(motor1[1], LOW);
  
      digitalWrite(motor2[0], HIGH);
      digitalWrite(motor2[1], LOW);
}
void  WheelController::TurnLeft()
{
      digitalWrite(motor1[0], LOW);
      digitalWrite(motor1[1], HIGH);
      delay(700);
}

