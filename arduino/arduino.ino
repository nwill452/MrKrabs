int motor2[] = {2, 3};
int motor1[] = {4, 5};

#define echoPin 8
#define trigPin 9

//long duration;
// Sup
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  pinMode(motor1[0], OUTPUT);
  pinMode(motor1[1], OUTPUT);
  pinMode(motor2[0], OUTPUT);
  pinMode(motor2[1], OUTPUT);
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

void loop() {

  int distance_no_err = distanceRemoveError(5);
  //Serial.print("Distance: ");
  Serial.println(distance_no_err);
  //Serial.println(" cm");

  if(distance_no_err < 76) 
  {
    // Moves towards target
    digitalWrite(motor1[0], LOW);
    digitalWrite(motor1[1], HIGH);

    digitalWrite(motor2[0], LOW);
    digitalWrite(motor2[1], HIGH); 
  } else if (distance_no_err > 75) {
    // Moves towards target
    digitalWrite(motor1[0], LOW);
    digitalWrite(motor1[1], LOW);

    digitalWrite(motor2[0], LOW);
    digitalWrite(motor2[1], LOW); 
  }
  /**else {
    // Spins in circle looking for target
    delay(200);
    digitalWrite(motor1[0], HIGH);
    digitalWrite(motor1[1], LOW);
    digitalWrite(motor2[0], HIGH);
    digitalWrite(motor2[1], LOW);

    delay(100);
    digitalWrite(motor1[0], HIGH);
    digitalWrite(motor1[1], LOW);
    digitalWrite(motor2[0], LOW);
    digitalWrite(motor2[1], LOW);
  }
**/
}