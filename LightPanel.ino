// This is a simple code to toggle switches as a joystick.
// Code is slightly different from the JoystickButton Example.
// Instead of setting the button state to On/Off, it quickly
// pushes and releases the button.  This works well for MSFS
// and X-Plane 11.
//
// Created By: Mike Cunico
// 11/2/2020
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 3;

// Last state of the button
int lastButtonState[9] = {0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 9; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.pressButton(index);
      delay(50);
      Joystick.releaseButton(index);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}
