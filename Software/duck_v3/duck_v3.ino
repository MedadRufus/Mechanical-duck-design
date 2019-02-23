
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


void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    servo_setup();
    radio_setup(); //impt


}


void loop()
{

    rc_read_values();
    rc_values[RC_CH1];

    // TODO: add a filter to the values. FIR
    //map the servo values
    //  val = map(val, 0, 1023, 0, 255);
    servo1_pos = map(rc_values[RC_CH1], 1050, 1750, 0, 180); // map channel 1
    set_servos(servo1_pos, servo2_pos);


    delay(20);

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


}
