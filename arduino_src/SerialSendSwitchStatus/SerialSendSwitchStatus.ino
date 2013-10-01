/*
  This program uses the HIVE Led/Switch shield for arduino uno.
  The program sends state of the switches over RS232 
  This example code is in the public domain.
 */

#include <stdio.h>  // Use the sprinf to generate strings

// Give names to the input pins
int sw0 = 14;
int sw1 = 15;
int sw2 = 16;
int sw3 = 17;
int sw4 = 18;

//The serial output buffer
char msg[100];

void setup() {
  // initialize serial:
  Serial.begin(9600);

  // make the switches input width pulup
  pinMode(sw0,  INPUT_PULLUP);
  pinMode(sw1,  INPUT_PULLUP);
  pinMode(sw2,  INPUT_PULLUP);
  pinMode(sw3,  INPUT_PULLUP);
}

void loop() {
   
  sprintf(msg,"$SW,%d,%d,%d,%d",
    digitalRead(sw0),digitalRead(sw1),
    digitalRead(sw2),digitalRead(sw3));
  
  Serial.println(msg);
    
}


