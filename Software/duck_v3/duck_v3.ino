
/*  Main code for running the Mechanical duck
    Created on Medad Newman on 22 Feb 2019
*/

#include "servo_driver.h"
#include "radio.h"
#include "main.h"
uint32_t rc_start[RC_NUM_CHANNELS];
uint16_t rc_values[RC_NUM_CHANNELS];



int servo1_pos = 20;  // desired angle for servo1
int servo2_pos = 20;  // desired angle for servo2
int i = 30;
int duck_speed = 0;
int rotation = 50;


void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    servo_setup();
    radio_setup(); //impt


}


void loop()
{
    /*  When the left right knob is not turned, go forward at speed set by the front stick.
        But if the left right passes a threshold, do the rotation.
    */
    rc_read_values();

    duck_speed = map(rc_values[RC_CH1], 1050, 1750, 0, 100); // map channel 1
    rotation = map(rc_values[RC_CH2], 1050, 1750, 0, 100); // map channel 2

    // IF the rotation signal is received, then rotate. Else, keep moving forward
    if ( !(20 < rotation < 80)) {

        if (rotation < 50) {
            turn_left();
        } else {
            turn_right();
        }
    } else {
        forward(duck_speed);
    }

    delay(20);
}
