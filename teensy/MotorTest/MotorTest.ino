/*
  Author: Ahmed Abbas (with the help of Oliver)
  Aim: Tests motors
*/


/* Global Variables */
#define R2_SPEED 7
#define R1_SPEED 8
#define L2_SPEED 9
#define L1_SPEED 10

#define R2_DIR 34
#define R1_DIR 33
#define L2_DIR 31
#define L1_DIR 32

#define MOTOR_ENABLE 43

#define FREQUENCY 300000

int dir = 0;

void setup() {

  setPins();
  setFrequencies();

}



void loop() {

  testMotors();
  
}
