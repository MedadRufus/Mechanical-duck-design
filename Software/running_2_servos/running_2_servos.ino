#define SERVO_SPEED 25 // (minimum number of milliseconds per degree)
#include <Servo.h>


int servo1_pos = 20;  // desired angle for servo1
int servo2_pos= 20;  // desired angle for servo2

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo

int i = 30;

void setup(){
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  
  
  }


void move_servos(){
   static unsigned long servo_time;

   // check time since last servo position update 
    if ((millis()-servo_time) >= SERVO_SPEED) {
   servo_time = millis(); // save time reference for next position update
   
   // update servo1 position
   // if desired position is different from current position move one step left or right
   if (servo1_pos > servo1.read()) servo1.write(servo1.read() + 1);
   else if (servo1_pos < servo1.read()) servo1.write(servo1.read() - 1);

   // update servo2 position
   // if desired position is different from current position move one step left or right
   if (servo2_pos > servo2.read()) servo2.write(servo2.read() + 1);
   else if (servo2_pos < servo2.read()) servo2.write(servo2.read() - 1);
 }
}

void set_servos(){
  servo1.write(servo1_pos);
    servo2.write(servo2_pos);

  
  }

void loop()
{

/*
  while (i<180){
    Serial.println("sajhdfsdf");
    servo1_pos = i;
    servo2_pos = i+80;
    move_servos();
    i+=1;
    }
*/
    // state 4
    Serial.println("state 4");
    servo1_pos = 120;
    servo2_pos = 40;
    set_servos();
    delay(200);
    

    // state 4.5
    Serial.println("state 4.5");
    servo1_pos = 120;
    servo2_pos = 170;
    set_servos();
    delay(300);

        // state 5
    Serial.println("state 5");
    servo1_pos = 30;
    servo2_pos = 120;
    set_servos();
    delay(200);


}
