/*
  Matrix Keypad Combination Lock Demo
  keypad-demo-lock.ino
  Combination lock using 4x4 matrix membrane keypad with Arduino
  Results on LCD display
  Drives relay

  DroneBot Workshop 2020
  https://dronebotworkshop.com

  Based upon code from https://www.circuitbasics.com/

*/

// Include Arduino Wire library for I2C
#include <Wire.h>
// Include LCD display library for I2C
#include <LiquidCrystal_I2C.h>
// Include Keypad library
#include <Keypad.h>
#include <Servo.h>


// Length of password + 1 for null character
#define Password_Length 8
// Character to hold password input
char Data[Password_Length];
// Password
char Master[Password_Length] = "ABC7890";

// Pin connected to lock relay input
int lockOutput = 13;

// Counter for character entries
byte data_count = 0;

// Character to hold key input
char customKey;

// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;

Servo myservo;
int pos = 0;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Create LCD object
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);  


void setup() {
  // Setup LCD with backlight and initialize
  lcd.backlight();
  lcd.init();

  // Set lockOutput as an OUTPUT pin
  pinMode(lockOutput, OUTPUT);
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
  closeLock();
}


void loop() {

  // Initialize LCD and print
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  // Look for keypress
  customKey = customKeypad.getKey();
  if (customKey) {
    // Enter keypress into array and increment counter
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }


  // See if we have reached the password length
  if (data_count == Password_Length - 1) {
    lcd.clear();

    if (!strcmp(Data, Master)) {
      // Password is correct
      lcd.print("Opening Lock");

      openLock();

      // Turn on relay for 5 seconds
      digitalWrite(lockOutput, HIGH);
      delay(10000);
      lcd.clear();

      digitalWrite(lockOutput, LOW);
       lcd.clear();
       lcd.print("Closing Lock");
    closeLock();

      
    }
    else {
      // Password is incorrect
      lcd.print("Incorrect");
      delay(1000);
    }

    // Clear data and LCD display
    lcd.clear();
    clearData();
  }
}

void clearData() {
  // Go through array and clear data
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}


void openLock() {
       for (pos = 180; pos >= 0; pos -= 1) { // goes from 360 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15ms for the servo to reach the position
        }
}

void closeLock() {
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 360 degrees
    // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10); 
     }
}
