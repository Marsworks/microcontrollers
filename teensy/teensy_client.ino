/*
Author: Ahmed Abbas
Aim: Direct ROS commands to the main Teensy
*/
#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt8.h>

#define MOTOR1 motor_1
#define MOTOR2 motor_2
#define MOTOR3 motor_3
#define MOTOR4 motor_4

ros::NodeHandle nh;
std_msgs::Float32 left_speed;
std_msgs::Float32 right_speed;
//base plate full 360
//wrist rot 360 (maybe 180)
//wrist up and down 90 each direction (180)
// wrist does not move sideways (yet)

void leftWheelCallback(const std_msgs::Float32 & leftwheel){
  // Electrical code here 
  Serial.println("Received");
}


void rightWheelCallback(const std_msgs::Float32 & rightwheel){
  // Electrical code here 
  Serial.println("Received");
}


void toggleCamCallback(const std_msgs::UInt8 &cam){
  // Toggle Camera
  if (cam.data == 1){
    //toggle left --
    //digitalWrite(LED_BUILTIN, HIGH);
  }
  else if(cam.data == 2){
    //toggle right ++
    //digitalWrite(LED_BUILTIN, LOW);
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
  
  Serial.begin(57600);  

}

void loop(){

  nh.spinOnce();
  
  delay(1);
}
