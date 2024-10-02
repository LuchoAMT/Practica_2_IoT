#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>

class LEDController {
private:
    const int led1, led2, led3, led4;

public:
    LEDController(int l1, int l2, int l3, int l4);
    void setup();
    void controlLEDs(const String& command);
};

#endif
