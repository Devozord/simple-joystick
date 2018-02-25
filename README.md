# Simple Joystick

Simple joystick library for Arduino.

## Install

Download zip, and then in your IDE go to `Sketch > Include library > Add .ZIP library`.

## How To Use

```c
#include "Joystick.h"

Joystick joystick;

const int VRx = 0;
const int VRy = 1;

void setup() {
  Serial.begin(115200);

  joystick.begin(VRx, VRy);
}

void loop() {
  joystick.onAction(fn);
  joystick.onLeft(fn);
  joystick.onRight(fn);
  joystick.onTop(fn);
  joystick.onBottom(fn);
}

void fn() {
 Serial.println("Joystick in use");
 delay(500);
}
```

- `VRx` is the X analogue pin number
- `VRy` is the Y analogue pin number