#include "UltraSound.h"



UltraSound::UltraSound(int eco, int trig)
{
  ecoport = eco;
  trigport = trig;
  pinMode(ecoport, OUTPUT);
  pinMode(trig, INPUT);
}

UltraSound::distanceRemoveError(int samples){
 int avg = 0;
   for( int i = 0; i < samples; i++  )
   {
       avg += getDistance();
   }

   return avg/samples ;  

}

UltraSound::getDistance(){
  long duration;
  digitalWrite(trigport, LOW);
  delayMicroseconds(2);
  digitalWrite(trigport, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigport, LOW);
  duration = pulseIn(ecoport, HIGH);

  distance = duration * 0.034 / 2;
  return distance;
}