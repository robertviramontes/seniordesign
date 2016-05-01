/*
 * This is the receiver end of our design.
 * 
 * Felipe, Robert, and Jessica
 */

#include <SoftwareSerial.h>


int pumpPin = 0;
int errorPin = 1;
int writePin = 3;
int readPin = 4;
int turn_on = '1';
int turn_off = '2';
int error = '3';
int filling;
int state;


SoftwareSerial serial(readPin, writePin);

void setup() {
  // put your setup code here, to run once:
  serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  pinMode(errorPin, OUTPUT);
  filling = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(serial.available()) {
    state = serial.read();
    if (state == turn_on && filling == 0) {
      digitalWrite(pumpPin, HIGH);
      filling = 1;
      digitalWrite(errorPin, LOW);
    }
    else if ( state == turn_off && filling == 1) {
      digitalWrite(pumpPin, LOW);
      filling = 0;
      digitalWrite(errorPin, LOW);
    }
    else if (state == error) {
      digitalWrite(errorPin, HIGH);
      digitalWrite(pumpPin, LOW);
    }
    else if (filling == 1) {
      digitalWrite(errorPin, LOW);
      digitalWrite(pumpPin, HIGH);
    }
    else if (filling == 0) {
      digitalWrite(errorPin, LOW);
      digitalWrite(pumpPin, LOW);
    }
  }

}
