/*
  4-digit 7-segment clock for ATmega8
  Common anode display controlled through BC547 transistors
  Active LOW segments (LOW = ON)
  Active HIGH digit select (HIGH = digit ON)
  Colon (:) blinks every second between digit 2 and digit 3
  Comments in English
*/

#include <Arduino.h>

// ----- Segment pin definitions -----
const int segA = 12; // segment A
const int segB = 8;  // segment B
const int segC = 3;  // segment C
const int segD = 1;  // segment D
const int segE = 0;  // segment E
const int segF = 11; // segment F
const int segG = 4;  // segment G
const int segDP = 2; // decimal point
const int segUC = 7; // colon cathode (UC/LC)

// ----- Digit control pins (through BC547 transistors) -----
const int digit1 = 13; // DIGIT 1
const int digit2 = 10; // DIGIT 2
const int digit3 = 9;  // DIGIT 3
const int digitUC_LC = 6; // Colon anode
const int digit4 = 5;  // DIGIT 4

// ----- Time variables -----
int hours = 21;
int minutes = 37;
int seconds = 0;

unsigned long previousMillis = 0;
bool colonState = true; // Blinking colon state
bool dotDigit1 = false;
bool dotDigit2 = true;
bool dotDigit3 = true;
bool dotDigit4 = false;

// ----- Segment patterns for digits 0–9 (active LOW) -----
const byte digitPatterns[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};

// ----- Setup -----
void setup() {
  // Segment pins
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  pinMode(segUC, OUTPUT);

  // Digit pins
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digitUC_LC, OUTPUT);
  pinMode(digit4, OUTPUT);

  allDigitsOff();
}

// ----- Helper functions -----

// Turn off all digits
void allDigitsOff() {
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digitUC_LC, LOW);
  digitalWrite(digit4, LOW);
}

// Display a digit (0–9)
void showNumber(int num, bool dot) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPin(i), digitPatterns[num][i]);
  }
  digitalWrite(segDP, !dot); // Decimal point off
}

// Return correct segment pin by index
int segmentPin(int index) {
  const int pins[7] = {segA, segB, segC, segD, segE, segF, segG};
  return pins[index];
}

// Show one number on a selected digit
void showDigit(int number, bool dot,  int digitPin) {
  allDigitsOff();         // Disable all digits
  showNumber(number, dot);     // Set segments
  digitalWrite(digitPin, HIGH); // Enable digit (active HIGH)
  delay(2);               // Small delay for persistence of vision
}

// Display the time HH:MM with blinking colon
void displayTime() {
  int d1 = hours / 10;
  int d2 = hours % 10;
  int d3 = minutes / 10;
  int d4 = minutes % 10;

  showDigit(d1, dotDigit1, digit1);
  showDigit(d2, dotDigit2, digit2);

  // Colon blink control
  if (colonState) {
    digitalWrite(segUC, LOW);     // Colon ON (active LOW)
    digitalWrite(digitUC_LC, HIGH);
    delay(2);
    digitalWrite(digitUC_LC, LOW);
    digitalWrite(segUC, HIGH);    // Turn colon OFF after brief flash
  }

  showDigit(d3, dotDigit3, digit3);
  showDigit(d4, dotDigit4, digit4);
}

/*
// ----- Time update -----
void updateTime() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    seconds++;

    // Blink colon every second
    colonState = !colonState;

    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) hours = 0;
      }
    }
  }
}
*/

// ----- Main loop -----
void loop() {
  // updateTime();
  for (int i = 0; i < 50; i++) {
    displayTime();
  }
}
