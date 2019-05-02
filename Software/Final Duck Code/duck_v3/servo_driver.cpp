
/*  The drivers for the servos
    Created on Medad Newman on 22 Feb 2019
    There are 2 servos, named upper and lower. These servos control the 2 degrees of freedom for the legs of the duck
*/
#include "servo_driver.h"
#include "main.h"
#include "Arduino.h"
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
Servo servo3;  // create servo object to control a servo
Servo servo4;  // create servo object to control a servo


/* generate the buffer as empty integer lists*/
const int lower_bottom = 30; // change this
const int upper_bottom = 120;
const int half_bottom_buffer_size = upper_bottom - lower_bottom + 1;
const int full_bottom_buffer_size = half_bottom_buffer_size * 2;



const int lower_top = 30;
const int upper_top = 120;
const int half_top_buffer_size = upper_top - lower_top + 1;
const int full_top_buffer_size = half_top_buffer_size * 2;


/* generate the buffer as empty integer lists. Populate later*/
int motor_1_path[full_top_buffer_size] ; // n is an array of 150 integers
int motor_2_path[full_bottom_buffer_size] ; // n is an array of 150 integers


int top_pointer = 0;
int bottom_pointer = 0;



/* function to assign pins to the servos */
void servo_setup() {
    servo1.attach(9);  // attaches the servo on pin 9 to the servo object
    servo2.attach(10);  // attaches the servo on pin 9 to the servo object

    servo3.attach(11);  // attaches the servo on pin 9 to the servo object
    servo4.attach(12);  // attaches the servo on pin 9 to the servo object
}



/* Initialise circular buffer for the bottom motor */
void intialise_circular_buffer_bottom() {
    int k = 0;
    for ( int i = lower_bottom; i <= upper_bottom; i++ ) // initialize elements of array n to 0
    {
        Serial.println(i);
        motor_1_path[k] = i; // set element at location i to 0
        k++;
    }

    for (int i = upper_bottom; i >= lower_bottom; i--) {

        motor_1_path[k] = i; // set element at location i to 0
        k++;
        Serial.println(i);

    }

}

/* Initialise circular buffer for the top motor */
void intialise_circular_buffer_top() {
    int k = 0;
    for ( int i = lower_top; i <= upper_top; i++ ) // initialize elements of array n to 0
    {
        motor_2_path[k] = i; // set element at location i to 0
        k++;
    }
    for (int i = upper_top; i >= lower_top; i--)
    {
        
        motor_2_path[k] = i; // set element at location i to 0
        k++;
    }

}


/* initialises both buffers at in one function */
void intialise_all_buffers() {
    intialise_circular_buffer_bottom();
    intialise_circular_buffer_top();
    
}


/* Function that drives the servos forwards */
void forward(int duck_speed) {

    while (1)
    {

        //leaps of duck_speed
        //loop around the circular buffer, making leaps
        //Serial.print("top point: ");Serial.print(top_pointer);Serial.print("duckspeed: ");Serial.println(duck_speed);Serial.print("\t");

        
        top_pointer = (top_pointer + duck_speed) % full_top_buffer_size;
        int pos_top = motor_1_path[top_pointer];

        bottom_pointer = (bottom_pointer + duck_speed) % full_bottom_buffer_size;
        int pos_bottom = motor_2_path[bottom_pointer];

        //Serial.print("top position: ");Serial.println(pos_top);Serial.print("\t");


        // in steps of 1 degree
        servo1.write(pos_top);              // tell servo to go to position in variable 'pos'
        servo2.write(pos_bottom);              // tell servo to go to position in variable 'pos'
        servo3.write(pos_top);              // tell servo to go to position in variable 'pos'
        servo4.write(pos_bottom);              // tell servo to go to position in variable 'pos'

        if (check_state_changed()){
            return;
        }

        delay(15);                       // waits 15ms for the servo to reach the position

    }

}


/* Function that drives the duck to the left */

void turn_left(int duck_speed) {

    while (1)
    {

        
        //leaps of duck_speed
        //loop around the circular buffer, making leaps
        //Serial.print("top point: ");Serial.print(top_pointer);Serial.print("duckspeed: ");Serial.println(duck_speed);Serial.print("\t");

        
        top_pointer = (top_pointer + duck_speed) % full_top_buffer_size;
        int pos_top = motor_1_path[top_pointer];

        bottom_pointer = (bottom_pointer + duck_speed) % full_bottom_buffer_size;
        int pos_bottom = motor_2_path[bottom_pointer];

        //Serial.print("top position: ");Serial.println(pos_top);Serial.print("\t");


        // in steps of 1 degree
        servo1.write(pos_top);              // tell servo to go to position in variable 'pos'
        servo2.write(pos_bottom);              // tell servo to go to position in variable 'pos'

        if (check_state_changed()){
            return;
        }

        delay(15);                       // waits 15ms for the servo to reach the position

    }


}

/* Function that drives the duck to the right */

void turn_right(int duck_speed) {

    while (1)
    {

        //leaps of duck_speed
        //loop around the circular buffer, making leaps
        //Serial.print("top point: ");Serial.print(top_pointer);Serial.print("duckspeed: ");Serial.println(duck_speed);Serial.print("\t");

        
        top_pointer = (top_pointer + duck_speed) % full_top_buffer_size;
        int pos_top = motor_1_path[top_pointer];

        bottom_pointer = (bottom_pointer + duck_speed) % full_bottom_buffer_size;
        int pos_bottom = motor_2_path[bottom_pointer];

        //Serial.print("top position: ");Serial.println(pos_top);Serial.print("\t");


        // in steps of 1 degree
        servo3.write(pos_top);              // tell servo to go to position in variable 'pos'
        servo4.write(pos_bottom);              // tell servo to go to position in variable 'pos'

        if (check_state_changed()){
            return;
        }

        delay(15);                       // waits 15ms for the servo to reach the position

    }
}


void set_servos(int servo1_pos, int servo2_pos) {
    servo1.write(servo1_pos);
    servo2.write(servo2_pos);
}



