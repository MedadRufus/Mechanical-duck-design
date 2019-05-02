
/*  Main code for running the Mechanical duck.
 *   Theere are 2 drivers used in this program: servo_driver.cpp and radio.cpp
 *   both contain header files as well. 
 *   The duck is a simple state machine: it has the forward state, turning left and turning right.
 *   The program reads the values from the 2 channels from the receiver and accordingly adjusts its state. 
 *   States are checked and updated every ~5ms
 *   
 *   Created on Medad Newman on 22 Feb 2019
*/

#include "servo_driver.h"
#include "radio.h"
#include "main.h"
uint32_t rc_start[RC_NUM_CHANNELS];
uint16_t rc_values[RC_NUM_CHANNELS];
int servo1_pos = 20;  // default angle for servo1
int servo2_pos = 20;  // default angle for servo2
int i = 30;
int ch1 = 0;
int ch2 = 50;
int duck_speed = 0;


states state = MOVING_FORWARD; //default state

void setup() {
    /* opens serial port, sets data rate to 9600 bps */
    Serial.begin(9600); 
    
    /* setup radio and servo drivers and buffers*/ 
    servo_setup(); // se
    radio_setup(); //impt
    intialise_all_buffers();

}


/* check if the state has changed. */
int check_state_changed() {
    rc_read_values();
    //print_receiver_values();

    /* current values from radio receiver */
    states current_state = state;
    int current_duck_speed = duck_speed;


    /* new values from receiver */
    ch2 = map(rc_values[RC_CH2], 900, 2000, 0, 180); // channel indicating direction. scale to 0-180 degrees
    duck_speed = constrain(map(rc_values[RC_CH1], 1100, 2000, 0, 10),0,6); // channel indicating speed


    /* read channel values to see if state has to change */
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


    /* now check if the state or speed has changed. if not changed, carry on.*/
    if (current_state != state || current_duck_speed != duck_speed ) {
        return 1;
    }

    return 0;
}



/* implementing a state machnine */
/* main loop*/
void loop() {

  
    check_state_changed();

    Serial.println(state);
    /* depending on the state, call that state function*/
    switch (state) {

        case MOVING_FORWARD:
            forward(duck_speed); 
            break;
        
        case TURNING_LEFT:
            turn_left(duck_speed);
            break;

        
        case TURNING_RIGHT:
            turn_right(duck_speed);
            break;
         
    }

    /* sleep for 5ms */
    delay(5);

}/* main */

