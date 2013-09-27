
#define MAX_RECV_LINE_LENGTH 200

String strIncompleteLine = "";   // a string to hold incoming data
String strInputLine = "";            // a string to the recieved line
boolean bStrComplete = false;    // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve MAX_RECV_LENGTH bytes for the inputString:
  strIncompleteLine.reserve(MAX_RECV_LINE_LENGTH);
  strInputLine.reserve(MAX_RECV_LINE_LENGTH);  
}

void loop() {
  // print the string when a newline arrives:
  if (bStrComplete) {
    Serial.print(strInputLine);
    // clear the string:
    strInputLine = "";
    bStrComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    strIncompleteLine += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      strInputLine=strIncompleteLine;
      bStrComplete = true;  
      strIncompleteLine="";      
    }
  }
}
