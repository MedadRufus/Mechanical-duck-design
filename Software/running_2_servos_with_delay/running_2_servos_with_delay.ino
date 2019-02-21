#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo

int pos1;      // angle of servo 1
int pos2;      // angle of servo2

void setup()
{
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop()
{
   //Scene 1:
   for (int i=0; i<80; i += 1) {
     pos1 = 130 - i;              // servo1 from 90 to 45 degrees
     pos2 = 0 + (i*2);           // servo2 from 0 to 90 degrees
  
     servo1.write(pos1);
     servo2.write(pos2);
     delay(15);                           // waits for the servo to get there
   }
  



  // Scene 2
  for (int i = 0; i < 80; i += 5) {
    pos1 = 45;                  // servo1 doesn't move
    pos2 = 130 + i;              // servo2 from 90 to 150 degrees
    servo1.write(pos1);
    servo2.write(pos2);
    delay(60);                           // waits for the servo to get there
  }
}
