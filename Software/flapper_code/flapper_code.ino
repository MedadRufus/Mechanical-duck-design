/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 Modified by Medad Newman, 18 Jan 2018
*/

#include <Servo.h>

Servo servoleft;  // create servo object to control a servo
Servo servoright;  // create servo object to control a servo

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  servoleft.attach(9);  // attaches the servo on pin 9 to the servo object
  servoright.attach(10);  // attaches the servo on pin 9 to the servo object

}

int start_pos  = 50;
int end_pos  = 180;
int pos_step = 2;
int offset = 50;


void loop() {
  for (pos = start_pos; pos <= end_pos; pos += pos_step) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoleft.write(180-(pos+offset));              // tell servo to go to position in variable 'pos'
    servoright.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = end_pos; pos >= start_pos; pos -= pos_step) { // goes from 180 degrees to 0 degrees
    servoleft.write(pos);              // tell servo to go to position in variable 'pos'
    servoright.write(180-(pos+offset));              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

