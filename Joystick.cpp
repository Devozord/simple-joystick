#include "Arduino.h"
#include "Joystick.h"

Joystick::Joystick() {}

void Joystick::begin(int VRx, int VRy, int tolerance) {
  vrx = VRx;
  vry = VRy;
  limit = tolerance;
  

  calX = analogRead(VRx);
  calY = analogRead(VRy);
}

void Joystick::onAction(void (*callback)(void)) {
  _readAnalogs();

  if ( isLeft() 
    || isRight() 
    || isTop() 
    || isBottom()
  ) {
    (*callback)();
  }
}

void Joystick::onLeft(void (*callback)(void)) {
  _readAnalogs();

  if ( isLeft() ) {
    (*callback)();
  }
}

void Joystick::onRight(void (*callback)(void)) {
  _readAnalogs();

  if ( isRight() ) {
    (*callback)();
  }
}

void Joystick::onTop(void (*callback)(void)) {
  _readAnalogs();

  if ( isTop() ) {
    (*callback)();
  }
}

void Joystick::onBottom(void (*callback)(void)) {
  _readAnalogs();

  if ( isBottom() ) {
    (*callback)();
  }
}

bool Joystick::isLeft() {
  return x > limit;
}

bool Joystick::isRight() {
  return x < -limit;
}

bool Joystick::isTop() {
  return y > limit;
}

bool Joystick::isBottom() {
  return y < -limit;
}

void Joystick::_readAnalogs(){
  x = analogRead(vrx) - calX;
  y = analogRead(vry) - calY;
}


