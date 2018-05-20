/*
   Code based on the "Crystal Ball" and "Knock Lock" projects in the Arduino Starter Kit
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// pin the piezo is attached to
const int piezo = A0;

unsigned int piezoValue = 0;
unsigned int laps = 0;

void setup() {
  // use the serial monitor
  Serial.begin(9600);
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  printToLcd();
}

void loop() {
  piezoValue = analogRead(piezo);
  Serial.println("Value: " + String(piezoValue));
  if (piezoValue > 1) {
    laps++;
    lcd.clear();
    printToLcd();
    delay(1000);
  }
}

void printToLcd() {
  lcd.setCursor(0, 0);
  lcd.print("Bjorn Rally");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Laps: " + String(laps));
}

