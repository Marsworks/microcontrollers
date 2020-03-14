/*
Author: Ahmed Abbas
Aim: Direct ROS commands to the main Teensy
*/

#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt8.h>


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

ros::NodeHandle nh;               // ROS Node
std_msgs::Float32 left_speed;     // ROS msg
std_msgs::Float32 right_speed;    // ROS msg
std_msgs::UInt8   cam_toggle;     // ROS msg

void leftWheelCallback(const std_msgs::Float32 & leftwheel){
  // Electrical code here 
  digitalWrite(L1_DIR, leftwheel.data < 0);
  analogWrite(L1_SPEED,map(leftwheel.data, -4.5,4.5,0,255));

}


void rightWheelCallback(const std_msgs::Float32 & rightwheel){
  // Electrical code here 
    digitalWrite(R1_DIR, rightwheel.data < 0);
    analogWrite(R1_SPEED,map(rightwheel.data, -4.5,4.5,0,255));
}


void toggleCamCallback(const std_msgs::UInt8 &cam){
  // Toggle Camera
  if (cam.data == 1){
    //toggle left --
  }
  else if(cam.data == 2){
    //toggle right ++
  }
}



ros::Subscriber <std_msgs::Float32> leftw_sub("/lwheel_vtarget",leftWheelCallback);
ros::Subscriber <std_msgs::Float32> rightw_sub("/rwheel_vtarget",rightWheelCallback);
ros::Subscriber <std_msgs::UInt8> cam_sub("/toggle_cam",toggleCamCallback);



void setup(){

  nh.initNode();
  
  nh.subscribe(leftw_sub);
  nh.subscribe(rightw_sub);
  nh.subscribe(cam_sub);
  
  //pinMode(LED_BUILTIN,OUTPUT);

  setPins();
  setFrequencies();
  testMotors();

}

void loop(){

  nh.spinOnce();
  
  delay(1);
}
