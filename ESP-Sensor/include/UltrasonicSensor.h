#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
private:
    const int triggerPin;
    const int echoPin;

public:
    UltrasonicSensor(int trigger, int echo);
    void setup();
    float getDistance();
};

#endif
