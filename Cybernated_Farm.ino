#include <Servo.h>

Servo myservo;  // create servo object to control a servo


int pos = 0;    // variable to store the servo position


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

// the loop routine runs over and over again forever:
void loop() {
  // read the moisture input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1000);        // delay in between reads for stability

  if (sensorValue < 300) // Soil is dry
  {                                  
    pos = 180;
    myservo.write(pos);              // tell servo to go to position 180
    delay(150);                       // waits 150ms for the servo to reach the position
  }
  else if (sensorValue >= 300 && sensorValue < 600)  // Soil is slightly moist
  {
    pos = 90;
    myservo.write(pos);              // tell servo to go to position 90
    delay(150);
  }
  else  // Soil is wet
  {
    pos = 0;
    myservo.write(pos);              // tell servo to go to position 0
    delay(150);
  }
}
