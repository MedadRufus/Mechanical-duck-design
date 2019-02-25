
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



// defining the states of the machine
enum states {
    TURING_LEFT,
    TURING_RIGHT,
    MOVING_FORWARD
};


enum states state = MOVING_FORWARD;
int secs = 0;


void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    servo_setup();
    radio_setup(); //impt
    enum states state = MOVING_FORWARD;


}


/* implementing a state machnine */
void loop() {
    

    rc_read_values();
    print_receiver_values();
    ch1 = map(rc_values[RC_CH1], 900, 2000, 0, 180); // map channel 1
    ch2 = map(rc_values[RC_CH2], 900, 2000, 0, 180); // map channel 2

    switch (state) {
        
        case MOVING_FORWARD:
            forward(duck_speed); // make sure LED is on
            break;
        case TURING_LEFT:
            led_off(); // make sure LED is off
            break;
        case TURING_RIGHT:
            led_on();
            break;
    }

    sleep(20); // sleep for 20ms
}



void loop()
{
    /*  When the left right knob is not turned, go forward at speed set by the front stick.
        But if the left right passes a threshold, do the rotation.
    */
    rc_read_values();
    print_receiver_values();

    ch1 = map(rc_values[RC_CH1], 900, 2000, 0, 180); // map channel 1
    ch2 = map(rc_values[RC_CH2], 900, 2000, 0, 180); // map channel 2
    //forward(duck_speed);
    //set_servos(duck_speed,rotation);



    // IF the rotation signal is received, then rotate. Else, keep moving forward
    //    if ( !(20 < rotation < 80)) {
    //
    //        if (rotation < 50) {
    //            turn_left();
    //        } else {
    //            turn_right();
    //        }
    //    } else {
    //        forward(duck_speed);
    //    }

    delay(20);
}
