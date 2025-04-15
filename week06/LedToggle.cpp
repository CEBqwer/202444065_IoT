#include "LedToggle.h"

LedToggle::LedToggle(int pin) {
    _pin = pin;
    _state = false;
    _delayTime = 0;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

LedToggle::LedToggle(int pin, unsigned long delayTime) {
    _pin = pin;
    _state = false;
    _delayTime = delayTime;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void LedToggle::toggle() {
    _state = !_state;
    digitalWrite(_pin, _state ? HIGH : LOW);
    if (_delayTime > 0) {
        delay(_delayTime);
    }
}
