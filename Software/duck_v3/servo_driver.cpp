
/*  The drivers for the servos
    Created on Medad Newman on 22 Feb 2019
*/
#include "servo_driver.h"
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo

void forward(int duck_speed) {
}

void turn_left() {

}
void turn_right() {
}



void set_servos(int servo1_pos, int servo2_pos) {
    servo1.write(servo1_pos);
    servo2.write(servo2_pos);
}

void servo_setup() {
    servo1.attach(9);  // attaches the servo on pin 9 to the servo object
    servo2.attach(10);  // attaches the servo on pin 9 to the servo object
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


