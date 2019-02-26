
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
int ch1 = 0;
int ch2 = 50;
int duck_speed = 10;

states state = MOVING_FORWARD;





void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    servo_setup();
    radio_setup(); //impt
}


void check_state() {
    rc_read_values();
    //print_receiver_values();
    ch1 = map(rc_values[RC_CH1], 900, 2000, 0, 180); // map channel 1 forward
    ch2 = map(rc_values[RC_CH2], 900, 2000, 0, 180); // map channel 2 leftright


    //    //IF the rotation signal is received, then rotate. Else, keep moving forward
    //    if  ch2 < 120) {
    //    Serial.println(ch2);
    //
    //        if () {
    //            //turn_left(duck_speed);
    //            states state = TURING_LEFT;
    //        } else {
    //            states state = TURING_RIGHT;
    //        }
    //    } else {
    //        states state = MOVING_FORWARD;
    //    }
//typedef enum {
//    TURING_LEFT,
//    TURING_RIGHT,
//    MOVING_FORWARD
//} states;


    //Serial.println(ch2);

    if (ch2 < 50)
    {
        state = TURNING_LEFT;
    }
    else if (ch2 > 120)
    {
        state = TURNING_RIGHT;
    }
    else
    {
        state = MOVING_FORWARD;
    }

    //Serial.println(state);
}

/* implementing a state machnine */
void loop() {

    check_state();

    switch (state) {

        case MOVING_FORWARD:
            forward(ch1); // make sure LED is on
            break;
        case TURNING_LEFT:
            turn_left(duck_speed); // make sure LED is off
            break;
        case TURNING_RIGHT:
            turn_right(duck_speed);
            break;
    }

    delay(5); // sleep for 5ms
}

