#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

class LedToggle {
    public:
        LedToggle(int pin);
        LedToggle(int pin, unsigned long delayTime);
        void toggle();

    private:
        int _pin;
        unsigned long _delayTime;
        bool _state;
};

#endif
