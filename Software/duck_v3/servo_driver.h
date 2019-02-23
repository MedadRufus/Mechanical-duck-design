/*  The drivers for the servos
    Created on Medad Newman on 22 Feb 2019
*/


#ifndef servo_driver_h
#define servo_driver_h


#include <Servo.h>



void set_servos(int servo1_pos, int servo2_pos);
void servo_setup();
void forward(int duck_speed);
void turn_left();
void turn_right();


#endif // servo_driver_h

