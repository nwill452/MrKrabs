#ifndef WheelController_h
#define WheelController_h

#include <Arduino.h>

class WheelController {
  private:
    int motor1[2];
    int motor2[2];

  public:
    WheelController(int wheel1[], int wheel2[]);
    void MoveForword();
    void MoveBackword();
    void TurnLeft();
    void TurnRight();

};
#endif
