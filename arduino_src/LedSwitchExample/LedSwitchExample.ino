/*
  This program uses the HIVE Led/Switch shield for arduino uno.
  The program displays the state of the switches on the corsponding leds
  This example code is in the public domain.
 */

// Give names to the input pins
int sw0 = 14;
int sw1 = 15;
int sw2 = 16;
int sw3 = 17;
int sw4 = 18;

// Give names to the output pins
int led0 = 8;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the switches input width pulup
  pinMode(sw0,  INPUT_PULLUP);
  pinMode(sw1,  INPUT_PULLUP);
  pinMode(sw2,  INPUT_PULLUP);
  pinMode(sw3,  INPUT_PULLUP);

  // make the Leds output width pulup  
  pinMode(led0,  OUTPUT );
  pinMode(led1,  OUTPUT );
  pinMode(led2,  OUTPUT );
  pinMode(led3,  OUTPUT );  
}

// the loop routine runs over and over again forever:
void loop() {

  //Copy the state of input to the output
  digitalWrite(led0,digitalRead(sw0));
  digitalWrite(led1,digitalRead(sw1));
  digitalWrite(led2,digitalRead(sw2));
  digitalWrite(led3,digitalRead(sw3));
  digitalWrite(led4,digitalRead(sw4));

  delay(1);        // delay in between reads for stability
}
