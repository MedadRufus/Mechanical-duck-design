
/*  Main code for running the Mechanical duck
    Created on Medad Newman on 22 Feb 2019
*/


// boiler plate code so far
#ifndef main_h
#define main_h

// defining the states of the machine
typedef enum {
    TURNING_LEFT,
    TURNING_RIGHT,
    MOVING_FORWARD
} states;

extern states state;

int check_state_changed();


#endif // main_h
