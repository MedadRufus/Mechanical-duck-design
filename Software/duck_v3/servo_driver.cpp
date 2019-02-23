
/*  The drivers for the servos
    Created on Medad Newman on 22 Feb 2019
*/
#include "servo_driver.h"
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo

void set_servos(int servo1_pos, int servo2_pos) {
    servo1.write(servo1_pos);
    servo2.write(servo2_pos);
}

void servo_setup() {
    servo1.attach(9);  // attaches the servo on pin 9 to the servo object
    servo2.attach(10);  // attaches the servo on pin 9 to the servo object
}
