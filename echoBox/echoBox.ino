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
const int outputDn = 2;
const int outputUp = 3;
const int trigger  = 6;
const int pingPin  = 7;
const int buttonDn = 8;
const int buttonUp = 9;

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
  long duration, debug;
  float inches;
  debug = 1;
  
  setUpState = digitalRead(buttonUp);
  setDnState = digitalRead(buttonDn);
  if (setDnState == LOW) {
    duration = 10000;
    while (duration > 2900) {
      digitalWrite(outputDn, HIGH);  
      delay(100); 
      pinMode(pingPin, OUTPUT);
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(5);
      digitalWrite(trigger, LOW);

      pinMode(pingPin, INPUT);
      duration = pulseIn(pingPin, HIGH);
      inches = microsecondsToInches(duration);
      if (debug = 1) {
        Serial.print(inches);
        Serial.print("in - ");
        Serial.print(duration);
        Serial.print("ms");
        Serial.println();
      }
    }
    digitalWrite(outputDn, LOW);
  }
  if (setUpState == LOW) {
    duration = 100;
    while (duration < 4650) {
      digitalWrite(outputUp, HIGH);  
      delay(200); 
      pinMode(pingPin, OUTPUT);
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(5);
      digitalWrite(trigger, LOW);

      pinMode(pingPin, INPUT);
      duration = pulseIn(pingPin, HIGH);
      inches = microsecondsToInches(duration);
      if (debug = 1) {
        Serial.print(inches);
        Serial.print("in - ");
        Serial.print(duration);
        Serial.print("ms");
        Serial.println();
      }
    }
    digitalWrite(outputUp, LOW); 
  }  
}

void getHeight() {
}

long microsecondsToInches(float microseconds)
{
  return microseconds / 74 / 2;
}
