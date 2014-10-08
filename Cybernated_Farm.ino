#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1000);        // delay in between reads for stability

  if (sensorValue < 300) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    pos = 180;
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(150);                       // waits 15ms for the servo to reach the position 
  } 
  else if (sensorValue >= 300 && sensorValue < 600)
  {
    pos = 90;
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(150); 
  }
  else
  {
    pos = 0;
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(150); 
  }
} 
