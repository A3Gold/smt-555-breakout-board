// Purpose: The Processing sketch to go with the scoreboard.
// Reference: https://bit.ly/2JDrEUq
// Author: A. Goldman
// Date: December 5, 2020
// Status: Working

import processing.serial.*; // Imports Serial library
Serial myPort;              // Creates object from Serial class
String score;               // Creates variable to store Serial data

void setup()
{
    size(500, 300);                            // Sets window size
    String portName = Serial.list()[3];        // Chooses the port
    myPort = new Serial(this, portName, 9600); // Assigns it
}

void draw()
{
    if (myPort.available() > 0)
    {                                         // If data available...
        score = myPort.readStringUntil('\n'); // Read until newline
    }
    background(0, 255, 50); // Sets backround colour
    try
    {
        textSize(70);            // Sets text size
        fill(200, 0, 50);        // Sets text colour
        text("Score:", 160, 60); // Prints text
        textSize(100);           // Sets text size
        fill(200, 0, 50);        // Sets text colour
        text(score, 215, 240);   // Prints text
    }
    catch (Exception e)
    { // If error in incoming data...
        // ignore
    }
}
