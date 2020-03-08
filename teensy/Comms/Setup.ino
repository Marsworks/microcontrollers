void setPins(){
  /* Pin setup */  
  
  pinMode(MOTOR1_SPEED,OUTPUT);
  pinMode(MOTOR1_DIR,OUTPUT);
  
  pinMode(MOTOR2_SPEED,OUTPUT);
  pinMode(MOTOR2_DIR,OUTPUT);
  
  pinMode(MOTOR3_SPEED, OUTPUT);
  pinMode(MOTOR3_DIR, OUTPUT);

  pinMode(MOTOR4_SPEED, OUTPUT);
  pinMode(MOTOR4_DIR, OUTPUT);
  
  pinMode(MOTOR_ENABLE,OUTPUT);
  
  digitalWrite(MOTOR_ENABLE,HIGH);
  
  digitalWrite(MOTOR1_DIR,HIGH);
  digitalWrite(MOTOR2_DIR,HIGH);  
  digitalWrite(MOTOR3_DIR,HIGH);
  digitalWrite(MOTOR4_DIR,HIGH);
  
  Serial.begin(9600);  
 
}

void setFrequencies(){
  /* Frequency Setup */
  analogWriteFrequency(MOTOR1_SPEED, 300000);
  analogWriteResolution(8);
  analogWrite(MOTOR1_SPEED, 0);
  
  analogWriteFrequency(MOTOR2_SPEED, 300000);
  analogWriteResolution(8);
  analogWrite(MOTOR2_SPEED, 0);

  analogWriteFrequency(MOTOR3_SPEED, 300000);
  analogWriteResolution(8);
  analogWrite(MOTOR3_SPEED, 0);

  analogWriteFrequency(MOTOR4_SPEED, 300000);
  analogWriteResolution(8);
  analogWrite(MOTOR4_SPEED, 0);

}

void testMotors(){
  /* motor tests */
  int i;
  for(i = 0; i <= 255; i++){
      analogWrite(MOTOR1_SPEED,i);
      analogWrite(MOTOR1_SPEED,i);
      analogWrite(MOTOR1_SPEED,i);
      analogWrite(MOTOR1_SPEED,i);
      delay(10);
  }

  delay(1000);
  
  for(; i >= 0; i--){
      analogWrite(MOTOR1_SPEED,i);
      analogWrite(MOTOR1_SPEED,i);
      analogWrite(MOTOR1_SPEED,i);
      analogWrite(MOTOR1_SPEED,i);
      delay(10);
  }

}
