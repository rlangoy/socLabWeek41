
#include <LiquidCrystal.h>

#define MAX_RECV_LINE_LENGTH 200
#define MAX_COMMANDS 10

String strIncompleteLine = ""; // a string to hold incoming data
String strInputLine = ""; // a string to the recieved line
boolean bStrComplete = false; // whether the string is complete

String strCommands[MAX_COMMANDS];

// Connections:
// rs (LCD )to Arduino pin 11
// rw (LCD) to Arduino pin 10
// enable (LCD ) to Arduino pin 9
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(11, 10, 9, 5, 4, 3, 2);

void setup()
{

  // initialize serial:
  Serial.begin(9600);
  // reserve MAX_RECV_LENGTH bytes for the inputString:
  strIncompleteLine.reserve(MAX_RECV_LINE_LENGTH);
  strInputLine.reserve(MAX_RECV_LINE_LENGTH);

  lcd.begin(16,2);              // Use 16,2 for a 16x2 LCD Module
  lcd.clear();                  // Clear screen
  lcd.setCursor(0,0);           // Set cursor to column 0, row 0 (the first row)
  lcd.print("Wating For");      // Display text at line 0
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  lcd.print("Serial Data");     // Display text at line 1 
}

// strCommands - input string that contains a CVS string ($LED,1,0,1,0,2)
// strTab - has the splited input (strTab[0]="$LED",strTab[1]="1",strTab[2]="0")
// maxItems - the maximum commands to parse
// Return the number of read items
int SplitCommands(String strCommands, String strTab[],int maxItems)
{
  //Start position looking for ','
  int fisrtCommaPosition=0;
  int lastCommaPosition=0;
  int iItems=0;
  do
    { //Get the position of the next item
        lastCommaPosition = strCommands.indexOf(',',fisrtCommaPosition);
        if(lastCommaPosition != -1)
        { strTab[iItems]= strCommands.substring(fisrtCommaPosition,lastCommaPosition);
            fisrtCommaPosition=lastCommaPosition+1;
        }
        else
            //Prints the last element
            strTab[iItems]= strCommands.substring(fisrtCommaPosition,strInputLine.length()-1);
      
       iItems++;

     } while((lastCommaPosition >=0) & (iItems<maxItems));

  return iItems;
}

void loop()
{
    int i=0;
  // print the string when a newline arrives:
  if (bStrComplete)
  { bStrComplete=false;
    // Splits the incoming string into strCommands[0] .. [MAX_COMMANDS]
    int nCommands=SplitCommands(strInputLine,strCommands,MAX_COMMANDS); // Parses the CVS string
    if(strCommands[0]=="$LCD")
    {
      lcd.clear();                  // Clear screen
      lcd.setCursor(0,0);           // Set cursor to column 0, row 0 (the first row)
      lcd.print(strCommands[1]);    // Display text at line 0
      lcd.setCursor(0,1);           // set cursor to column 0, row 1
      lcd.print(strCommands[2]);    // Display text at line 1 
    }
  }
} 

/*
SerialEvent occurs whenever a new data comes in the
hardware serial RX. This routine is run between each
time loop() runs, so using delay inside loop can delay
response. Multiple bytes of data may be available.
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
