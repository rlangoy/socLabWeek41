
#define MAX_RECV_LINE_LENGTH 200
#define MAX_COMMANDS 10

String strIncompleteLine = "";   // a string to hold incoming data
String strInputLine = "";        // a string to the recieved line
boolean bStrComplete = false;    // whether the string is complete

String strCommands[MAX_COMMANDS];

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve MAX_RECV_LENGTH bytes for the inputString:
  strIncompleteLine.reserve(MAX_RECV_LINE_LENGTH);
  strInputLine.reserve(MAX_RECV_LINE_LENGTH);  
}

//  strCommands - input string that contains a CVS string ($LED,1,0,1,0,2)
//  strTab - has the splited input (strTab[0]="$LED",strTab[1]="1",strTab[2]="0")
//  maxItems -  the maximum commands to parse
//  Return the number of read items
int SplitCommands(String  strCommands, String strTab[],int maxItems)
{
  //Start position looking for ','
  int fisrtCommaPosition=0; 
  int lastCommaPosition=0;
  int iItems=0;
  do
    { //Get the position of the next item
        lastCommaPosition = strCommands.indexOf(',',fisrtCommaPosition);
        if(lastCommaPosition != -1)
        {   strTab[iItems]= strCommands.substring(fisrtCommaPosition,lastCommaPosition);
            fisrtCommaPosition=lastCommaPosition+1;             
        }
        else
            //Prints the last element
            strTab[iItems]= strCommands.substring(fisrtCommaPosition,strInputLine.length());
      
       iItems++; 

     } while((lastCommaPosition >=0) & (iItems<maxItems));    

  return iItems;
}

//Main loop do the work :)
void loop() 
{
  int i=0;
  // print the string when a newline arrives:
  if (bStrComplete) 
  { bStrComplete=false;
    // Splits the incoming string into strCommands[0] .. [MAX_COMMANDS]
    int nCommands=SplitCommands(strInputLine,strCommands,MAX_COMMANDS); // Parses the CVS string
    for(i=0;i<nCommands;i++)
      Serial.println(strCommands[i]);  //Display the content of the table  
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
