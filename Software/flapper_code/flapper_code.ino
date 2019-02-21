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



int start_pos  = 50;
int end_pos  = 180;
int pos_step = 2;
int offset = 50;
int direction_;


void setup() {
  servoleft.attach(9);  // attaches the servo on pin 9 to the servo object
  servoright.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps


}
void loop(){
  move_motor(servoright,30,180,3);
  move_motor(servoleft,180,,3);

  delay(500);
}

void move_motor(Servo &motor,int start_pos,int end_pos,int motor_speed){
    direction_ = start_pos - end_pos;
   Serial.println("heresd" );
   Serial.println(direction_);

   if (direction_ < 0){
          for (pos = start_pos; pos <= end_pos; pos += motor_speed) { // goes from 0 degrees to 180 degrees
          motor.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
   }else{
        for (pos = start_pos; pos >= end_pos; pos -= motor_speed) { // goes from 0 degrees to 180 degrees
        motor.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }   
   }
}


