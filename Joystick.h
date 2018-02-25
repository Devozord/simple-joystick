//Joystick.h
 
#ifndef Joystick_h
  #define Joystick_h

#include "Arduino.h"

class Joystick {
  public:
    Joystick();
    void begin(int VRx, int VRy, int tolerance = 200);

    // Pins
    int vrx;
    int vry;

    // Calibration
    int calX;
    int calY;

    // Current values
    int x;
    int y;
    int limit;

    // Events
    void onAction(void (*callback)(void));
    void onLeft(void (*callback)(void));
    void onRight(void (*callback)(void));
    void onTop(void (*callback)(void));
    void onBottom(void (*callback)(void));
    
    // Helpers 
    bool isLeft();
    bool isRight();
    bool isTop();
    bool isBottom();

  private: 
    void _readAnalogs();
};
  
#endif
