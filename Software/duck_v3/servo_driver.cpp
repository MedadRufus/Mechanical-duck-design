
/*  The drivers for the servos
    Created on Medad Newman on 22 Feb 2019
*/
#include "servo_driver.h"
#include "main.h"
#include "Arduino.h"
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
Servo servo3;  // create servo object to control a servo
Servo servo4;  // create servo object to control a servo

int upstroke_mult = 0.5;
int pos = 0;

// save last servo position

/* Function that drives the servos forwards */
void forward(int duck_speed) {

    while (1)
    {

        for (pos = 30; pos <= 120; pos += 5) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            servo1.write(pos);              // tell servo to go to position in variable 'pos'
            servo2.write(pos);              // tell servo to go to position in variable 'pos'
            servo3.write(pos);              // tell servo to go to position in variable 'pos'
            servo4.write(pos);              // tell servo to go to position in variable 'pos'

            check_state();
            if (state != MOVING_FORWARD){return;}
            
            delay(15);                       // waits 15ms for the servo to reach the position
        }
        
        for (pos = 120; pos >= 30; pos -= 5) { // goes from 180 degrees to 0 degrees
            servo1.write(pos);              // tell servo to go to position in variable 'pos'
            servo2.write(pos);              // tell servo to go to position in variable 'pos'
            servo3.write(pos);              // tell servo to go to position in variable 'pos'
            servo4.write(pos);              // tell servo to go to position in variable 'pos'

            check_state();
            if (state != MOVING_FORWARD){return;}
            
            delay(15);                       // waits 15ms for the servo to reach the position
        }
    }
   
}

void turn_left(int duck_speed) {

    while (1)
    {

        for (pos = 30; pos <= 120; pos += 5) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            servo1.write(pos);              // tell servo to go to position in variable 'pos'
            servo2.write(pos);              // tell servo to go to position in variable 'pos'

            check_state();
            if (state != TURNING_LEFT){return;}
            
            delay(15);                       // waits 15ms for the servo to reach the position
        }
        
        for (pos = 120; pos >= 30; pos -= 5) { // goes from 180 degrees to 0 degrees
            servo1.write(pos);              // tell servo to go to position in variable 'pos'
            servo2.write(pos);              // tell servo to go to position in variable 'pos'

            check_state();
            if (state != TURNING_LEFT){return;}
            
            delay(15);                       // waits 15ms for the servo to reach the position
        }
    }
   

}
void turn_right(int duck_speed) {
    while (1)
    {

        for (pos = 30; pos <= 120; pos += 5) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            servo3.write(pos);              // tell servo to go to position in variable 'pos'
            servo4.write(pos);              // tell servo to go to position in variable 'pos'

            check_state();
            if (state != TURNING_RIGHT){return;}
            
            delay(15);                       // waits 15ms for the servo to reach the position
        }
        
        for (pos = 120; pos >= 30; pos -= 5) { // goes from 180 degrees to 0 degrees
            servo3.write(pos);              // tell servo to go to position in variable 'pos'
            servo4.write(pos);              // tell servo to go to position in variable 'pos'

            check_state();
            if (state != TURNING_RIGHT){return;}
            
            delay(15);                       // waits 15ms for the servo to reach the position
        }
    }

    
}



void set_servos(int servo1_pos, int servo2_pos) {
    servo1.write(servo1_pos);
    servo2.write(servo2_pos);
}

void servo_setup() {
    servo1.attach(9);  // attaches the servo on pin 9 to the servo object
    servo2.attach(10);  // attaches the servo on pin 9 to the servo object
    
    servo3.attach(11);  // attaches the servo on pin 9 to the servo object
    servo4.attach(12);  // attaches the servo on pin 9 to the servo object
}



// ADDITIONAL functions
/*
    // state 4
    Serial.println("state 4");
    servo1_pos = 50;
    servo2_pos = 70;
    set_servos(servo1_pos,servo2_pos);
    delay(1000);

    /*
    // state 4.5
    Serial.println("state 4.5");
    servo1_pos = 120;
    servo2_pos = 170;
    set_servos();
    delay(1000);

      // state 5
    Serial.println("state 5");
    servo1_pos = 30;
    servo2_pos = 120;
    set_servos();
    delay(1000);
*/


