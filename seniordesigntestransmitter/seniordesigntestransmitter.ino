/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

 #include <SoftwareSerial.h>


int switchHiPin = 0;
int bottomSwitchTest = 1;
int topSwitchTest = 2;
int writePin = 3;
int readPin = 4;
int turn_on = '1';
int turn_off = '2';
int error = '3';

SoftwareSerial serial(readPin, writePin);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  serial.begin(9600);
  pinMode(writePin, OUTPUT);
  pinMode(switchHiPin, OUTPUT);
  pinMode(topSwitchTest, INPUT);
  pinMode(bottomSwitchTest, INPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  // print out the state of the button:

  digitalWrite(switchHiPin, HIGH);
  delay(500);
  
  int top = digitalRead(topSwitchTest);
  int bottom  = digitalRead(bottomSwitchTest);


  if(top==HIGH && bottom == HIGH) {
    serial.write(turn_off);
  }
  else if (top == LOW && bottom == LOW){ 
    serial.write(turn_on);
  }
  else if (top == HIGH && bottom == LOW) {
    // PANIC
    serial.write(error);
  }
  // else filling, do nothing
  digitalWrite(switchHiPin, LOW);
  delay(500);        // delay in between reads for stability
}



