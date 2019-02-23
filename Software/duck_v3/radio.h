/*  Code for listening to the receiver
    Created on Medad Newman on 22 Feb 2019
*/

#ifndef Radio_h
#define Radio_h

#include <stdint.h>

#define RC_CH1  0
#define RC_CH2  1
#define RC_CH3  2
#define RC_CH4  3

#define RC_CH1_INPUT  A0
#define RC_CH2_INPUT  A1
#define RC_CH3_INPUT  A2
#define RC_CH4_INPUT  A3

#define RC_NUM_CHANNELS  4

extern uint32_t rc_start[RC_NUM_CHANNELS];
extern uint16_t rc_values[RC_NUM_CHANNELS];

void print_receiver_values(); //impt
void rc_read_values();
void calc_input(uint8_t channel, uint8_t input_pin);
void calc_ch1();
void calc_ch2();
void calc_ch3();
void calc_ch4();
void radio_setup(); //impt


#endif // RADIO_H
