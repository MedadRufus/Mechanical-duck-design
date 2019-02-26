
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

void check_state();


#endif // main_h
