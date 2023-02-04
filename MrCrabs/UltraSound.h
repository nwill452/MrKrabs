#ifndef UltraSound_h
#define UltraSound_h

#include <Arduino.h>

class UltraSound{
  private:
  int ecoport;
  int trigport;
  int distance;
  



  public:
  UltraSound(int ecoport, int trigport);
  int distanceRemoveError(int samples);
  int getDistance();





};

#endif
