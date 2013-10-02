#include <LiquidCrystal.h>

// Connections:
// rs (LCD )to Arduino pin 11
// rw (LCD) to Arduino pin 10
// enable (LCD ) to Arduino pin 9
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(11, 10, 9, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16,2);              // Use 16,2 for a 16x2 LCD Module
  lcd.clear();                  // Clear screen
  lcd.setCursor(0,0);           // Set cursor to column 0, row 0 (the first row)
  lcd.print("Text Line 0");      // Display text at line 0
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  lcd.print("Text Line 1");     // Display text at line 1 
}

void loop()
{

}
