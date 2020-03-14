/*
 * Setup functions
 */

void setPins(){
  // L1
  pinMode(pwmpin,OUTPUT);
  pinMode(dir,OUTPUT);
  //L2
  pinMode(pinL2,OUTPUT);
  pinMode(dirL2,OUTPUT);
  //R1
  pinMode(pinR1, OUTPUT);
  pinMode(pinR1, OUTPUT);
  
  pinMode(onoff,OUTPUT);
  
  digitalWrite(onoff,HIGH);
  digitalWrite(dir,LOW);
  digitalWrite(dirL2,LOW);
  digitalWrite(dirR1,LOW);
  


  Serial.begin(9600);  
 
}

void setFrequencies(){
  analogWriteFrequency(pwmpin, 300000);
  analogWriteResolution(8);
  analogWrite(pwmpin, 0);
  
  analogWriteFrequency(pinL2, 300000);
  analogWriteResolution(8);
  analogWrite(pinL2, 0);

  analogWriteFrequency(pinR1, 300000);
  analogWriteResolution(8);
  analogWrite(pinL2, 0);

}
