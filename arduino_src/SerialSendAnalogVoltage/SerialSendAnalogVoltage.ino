
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
   Serial.begin(9600);
   //--
   pinMode(14,  OUTPUT );  // Left leg of potentiomenter
                           // A1 is the Midle leg is input 
   pinMode(16,  OUTPUT );  // Right leg of potentiomenter
   digitalWrite(14,LOW);   //
   digitalWrite(16,HIGH);  //
}

// the loop routine runs over and over again forever:
void loop() {
  float oldVoltage=-1;
  while(true)
  { // read the input on analog pin 0:
    int sensorValue = analogRead(A1);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    if(voltage!=oldVoltage) //Transfer voltage on change
    {  
      //Transfer the serial data
      Serial.print("$VOLTAGE,A1," );
      Serial.println(voltage);
    }//end if
  }//end while
}
