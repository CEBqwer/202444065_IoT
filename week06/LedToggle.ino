#include <LedToggle.h>

LedToggle led(LED_BUILTIN, 500);

void setup() {}

void loop() {
  led.toggle();
}
