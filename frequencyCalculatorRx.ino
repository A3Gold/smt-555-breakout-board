// Purpose: The Processing sketch to go with the frequency calculator.
// Reference: https://bit.ly/2JDrEUq
// Author: A. Goldman
// Date: December 5, 2020
// Status: Working

import processing.serial.*; // Imports Serial library
Serial myPort;              // Creates object from Serial class
String frequency;           // Creates variable to store Serial data

void setup()
{
    size(400, 400);                            // Sets window size
    String portName = Serial.list()[3];        // Chooses the port
    myPort = new Serial(this, portName, 9600); // Assigns it
}

void draw()
{
    if (myPort.available() > 0)
    {                                             // If data available...
        frequency = myPort.readStringUntil('\n'); // Read until newline
    }
    background(55, 0, 230); // Sets backround colour
    try
    {
        textSize(40);                    // Sets text size
        fill(240, 0, 50);                // Sets text colour
        text("Frequency (Hz):", 40, 50); // Prints text
        textSize(30);                    // Sets text size
        fill(50, 200, 100);              // Sets text colour
        text(frequency, 40, 80);         // Prints text
    }
    catch (Exception e)
    { // If error in incoming data...
        // ignore
    }
}
