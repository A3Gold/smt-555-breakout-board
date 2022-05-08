// Purpose: A simple Serial plotter scope simulation for use with the BoBs.
// Reference: https://bit.ly/2JDrEUq
// Author: A. Goldman
// Date: December 5, 2020
// Status: Working

#define INPUTPIN A0  // Defines the input pin
#define BUTTONPIN A1 // Defines the button pin

void setup()
{
    Serial.begin(9600); // Initializes the Serial Monitor
}

void loop()
{
    if (digitalRead(BUTTONPIN) == LOW)
    {                                          // If pause button off,
        Serial.println(digitalRead(INPUTPIN)); // Read input pin, print
    }
}
