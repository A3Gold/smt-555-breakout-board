// Purpose: A score board simulation for the debouncer BoB, to be used with
// Processing.
// Reference: https://bit.ly/2JDrEUq
// Author: A. Goldman
// Date: December 5, 2020
// Status: Working

#define INTERRUPTPIN 2 // Defines interrupt pin
uint16_t score = 0; // Defines score variable; starts at 0

void setup() {
Serial.begin(9600); // Initializes Serial Monitor
// ISR every time falling edge on pin interrupt pin...
attachInterrupt(digitalPinToInterrupt(INTERRUPTPIN), ISR_Add, FALLING);
}

void ISR_Add() { // Triggered on button press...
score++; // Increases score by 1
Serial.println(score); // Prints score to Serial Monitor
}

void loop() {
delay(10); // Delay to support functionality
}
