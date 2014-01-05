/*
 echoBox
   This is a sketch that controls the control box for my desk at work.
   It is a motorized desk that requires you to hold the button until 
   it gets to the correct height. 
   
   This will allow me to program a height and press a button to get the 
   desk to the correct location.
 */

// set pin numbers:
#include <SoftwareSerial.h>
const int outputUp = 2;
const int outputDn = 3;
const int trigger  = 6;
const int pingPin  = 7;
const int buttonUp = 8;
const int buttonDn = 9;

// variables will change:
int setUpState = 0;
int setDnState = 0;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(outputUp, OUTPUT);     
  pinMode(outputDn, OUTPUT);     
  pinMode(buttonUp, INPUT);     
  pinMode(buttonDn, INPUT);     
  Serial.begin(9600);
}

void loop(){
  long duration, inches, debug;
  debug = 1;
  
  setUpState = digitalRead(buttonUp);
  setDnState = digitalRead(buttonDn);
  if (setDnState == LOW) {
    digitalWrite(outputDn, HIGH);  
    delay(10000);
    digitalWrite(outputDn, LOW); 
  }
  if (setUpState == LOW) {
    digitalWrite(outputUp, HIGH);  
    delay(10000);
    digitalWrite(outputUp, LOW); 
  }
  
}
