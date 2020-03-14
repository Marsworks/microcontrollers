void setPins(){
  /* Pin setup */
  
  pinMode(R2_DIR, OUTPUT);
  pinMode(R1_DIR, OUTPUT);
  pinMode(L2_DIR, OUTPUT);
  pinMode(L1_DIR, OUTPUT);

  pinMode(MOTOR_ENABLE, OUTPUT);

  digitalWrite(MOTOR_ENABLE, HIGH);

  digitalWrite(R2_DIR, LOW);
  digitalWrite(R1_DIR, LOW);
  digitalWrite(L2_DIR, HIGH);
  digitalWrite(L1_DIR, HIGH);

  Serial.begin(9600);
 
}

void setFrequencies(){
  /* Frequency Setup */
  
  analogWriteFrequency(R2_SPEED, FREQUENCY);
  analogWriteResolution(8);
  //analogWrite(R2_SPEED, 0);

  analogWriteFrequency(R1_SPEED, FREQUENCY);
  analogWriteResolution(8);
  //analogWrite(R1_SPEED, 0);

  analogWriteFrequency(L2_SPEED, FREQUENCY);
  analogWriteResolution(8);
  //analogWrite(L2_SPEED, 0);

  analogWriteFrequency(L1_SPEED, FREQUENCY);
  analogWriteResolution(8);
  //analogWrite(L1_SPEED, 0);

}


void testMotors(){
  /* test motors */

  /* Change Direction */
  dir = abs(dir-1);
  digitalWrite(R2_DIR, dir);
  digitalWrite(R1_DIR, dir);
  digitalWrite(L2_DIR, abs(dir-1));
  digitalWrite(L1_DIR, abs(dir-1));
  
   /* Ramp up */
   for(int i = 0; i <= 250; i++){
        analogWrite(R1_SPEED,i);
        analogWrite(L1_SPEED,i);
        analogWrite(R2_SPEED,i);
        analogWrite(L2_SPEED,i);
        delay(10);
    }
  
    delay(1000);

    /* Ramp down */
    for(int i = 250; i >= 00; i--){
        analogWrite(R1_SPEED,i);
        analogWrite(L1_SPEED,i);
        analogWrite(R2_SPEED,i);
        analogWrite(L2_SPEED,i);
        delay(10);
    }
  
    delay(1000);
  
}
