/*
 * Author: Ahmed Abbas (with the help of Oliver
 * Aim: Test motor functionality because we don't actually have the code yet
 */

const int pwmpin = 8;//10; //TX
const int dir = 7;//9; //RX
const int pinL2 = 10;
const int dirL2 = 9;
const int pinR1 = 34; // TX;
const int dirR1 = 33; // RX;

const int onoff = 43;
int currSpeed = 0;
String data = String("");

void setup() {
  setPins();
  setFrequencies();

  Serial.begin(9600);
  //Serial.setTimeout(5000);
}

void loop() {
  
  data = Serial.readString();
  
  if(data != ""){
    Serial.println(data);
    ramp(pinL2, data.toInt(),currSpeed);
    //ramp(pwmpin,data.toInt(),currSpeed);
    currSpeed = data.toInt();
    }

 
  data = String("");
  
}


void ramp(int pin, int desSpeed, int currentSpeed){
  if( currentSpeed > desSpeed){
    for(int i = currentSpeed; i >= desSpeed; i--){
      analogWrite(pwmpin,i);
      analogWrite(pinR1,i);
      delay(10);
      }
    }else{
          for(int i = currentSpeed; i<= desSpeed; i++){
      analogWrite(pwmpin,i);
      analogWrite(pinR1,i);
      delay(10);
      }
  }
}
