/*
 outputSwitching
 
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int outputUp = 2;
const int outputDn = 3;
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
  
}

void loop(){
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
