int motor2[] = {2, 3};
int motor1[] = {4, 5};

#define echoPin 8
#define trigPin 9
#define lightPin 13

//long duration;
// Sup
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lightPin, INPUT);
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

void run(bool go) {
  if (go) {
    // Moves towards target
    digitalWrite(motor1[0], LOW);
    digitalWrite(motor1[1], HIGH);

    digitalWrite(motor2[0], LOW);
    digitalWrite(motor2[1], HIGH);    
  } else {
    // No movement
    digitalWrite(motor1[0], LOW);
    digitalWrite(motor1[1], LOW);

    digitalWrite(motor2[0], LOW);
    digitalWrite(motor2[1], LOW);
  }
}

void backwards() {
// Backwards
  digitalWrite(motor1[0], HIGH);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor2[0], HIGH);
  digitalWrite(motor2[1], LOW);
  delay(900);  
}

void spin_180() {
  // Turns around with both wheels moving in different directions
  digitalWrite(motor1[0], HIGH);
  digitalWrite(motor1[1], LOW);

  digitalWrite(motor2[0], LOW);
  digitalWrite(motor2[1], HIGH);
  delay(500);
}

void roundabout() {

  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  int loop_count = 0;

  while ((endtime - starttime) <= 1000) {

    digitalWrite(motor1[0], LOW);
    digitalWrite(motor1[1], HIGH);

    if (loop_count % 4 == 0) {
      digitalWrite(motor2[0], LOW);
      digitalWrite(motor2[1], HIGH);
    }

    delay(300);

    endtime = millis();
    loop_count++;
  }

  starttime = millis();
  endtime = starttime;
  loop_count = 0;

  while ((endtime - starttime) <= 1000) {
    
    digitalWrite(motor2[0], LOW);
    digitalWrite(motor2[1], HIGH);

    if (loop_count % 4 == 0) {
      digitalWrite(motor1[0], LOW);
      digitalWrite(motor1[1], HIGH);
    }

    delay(300);

    endtime = millis();
    loop_count++;
  }
  
  Serial.println("Done!");
}

void loop() {
  // print current time
  
  int distance_no_err = distanceRemoveError(5);
  int detect = digitalRead(lightPin);
  //Serial.print("Distance: ");
  Serial.println(distance_no_err);
  //Serial.println(" cm");

  // detect is HIGH on black, every other colour is LOW
  if (detect == HIGH) {
    Serial.println("High");
  } else if (detect == LOW) {
    Serial.println("Low");
  }

  if (detect == HIGH) {
    // backs up while still on black and then spins when it detects otherwise
    while (detect == HIGH) {
      backwards();
      detect = digitalRead(lightPin);
      if (detect == HIGH) {
        Serial.println("High");
      } else if (detect == LOW) {
        Serial.println("Low");
      }
    }
    spin_180();
  } else if (distance_no_err < 25) {
    roundabout();
  } else if (distance_no_err < 76 && detect == LOW) {
    // Moves towards target
    run(true);
  } else if (distance_no_err > 75) {
    // Stops moving entirely
    run(false);
  }
}