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

  int statusSw0 = digitalRead(sw0);
  int statusSw1 = digitalRead(sw1);
  int statusSw2 = digitalRead(sw2);
  int statusSw3 = digitalRead(sw3);

  while(true) 
  {
    //Check if the state of the switches has changed
    if ( (statusSw0!=digitalRead(sw0)) |
         (statusSw1!=digitalRead(sw1)) |
         (statusSw2!=digitalRead(sw2)) |
         (statusSw3!=digitalRead(sw3)) )
      { //Transfer the new switch walues      

       //Store the new values
       statusSw0 = digitalRead(sw0);
       statusSw1 = digitalRead(sw1);
       statusSw2 = digitalRead(sw2);
       statusSw3 = digitalRead(sw3);

       //Make the string to transfer
       sprintf(msg,"$SW,%d,%d,%d,%d",
        digitalRead(sw0),digitalRead(sw1),
        digitalRead(sw2),digitalRead(sw3));
       
       //Transfer the serial data
       Serial.println(msg);
      }//end if
  }//end while
    
}


