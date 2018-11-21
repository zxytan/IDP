/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo_right;  // create servo object to control a servo
Servo myservo_left;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo_right.attach(9);
  myservo_left.attach(10);// attaches the servo on pin 9 to the servo object
}

void loop() {
  //for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  myservo_right.write(150);              // tell servo to go to position in variable 'pos'
  myservo_left.write(-30);
  delay(3000);                       // waits 15ms for the servo to reach the position
  //}
  //for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  myservo_right.write(30);
  myservo_left.write(115); // tell servo to go to position in variable 'pos'
  delay(3000);                       // waits 15ms for the servo to reach the position
  //}
}
