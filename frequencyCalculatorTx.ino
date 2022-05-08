// Purpose: A frequency calculator to be used with the BoBs and Processing.
// Reference: https://bit.ly/2JDrEUq
// Author: A. Goldman
// Date: December 5, 2020
// Status: Working

#include <TimerOne.h>          // Includes Timer1 library
#define INTERRUPTPIN 2         // Defines interrupt pin
volatile uint8_t count;        // Defines count variable
float countCopy;               // Defines count copy variable
volatile uint8_t periodUp = 0; // Defines period up variable
float frequency = 0;           // Defines frequency variable

void setup()
{
    Serial.begin(9600); // Initializes Serial Monitor
    // ISR every time falling edge on pin interrupt pin...
    attachInterrupt(digitalPinToInterrupt(INTERRUPTPIN), ISR_Count, FALLING);
    Timer1.initialize(5000000);            // Initializes Timer1 period
    Timer1.attachInterrupt(ISR_Calculate); // ISR when period up
}

void ISR_Count()
{            // Triggered on falling edge...
    count++; // Adds one to count
}

void ISR_Calculate()
{                 // Triggered when period up...
    periodUp = 1; // Sets period up equal to 1
}

void loop()
{
    if (periodUp)
    {
                                    // If period up == 1...
        countCopy = count;       // Copy count variable
        count = 0;                   // Set it equal to 0
        periodUp = 0;                // Set period up equal to 0
        frequency = (countCopy / 5); // Calculate frequency
        Serial.println(frequency);   // Print to Serial Monitor
    }
}
