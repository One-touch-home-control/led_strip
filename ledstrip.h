#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include "Arduino.h"
#include <FastLED.h>

void FillLEDsFromPaletteColors(uint8_t colorIndex);
void SetupAllColor(CRGB color);
void led_push_all_color(CRGB in_color);
void led_init();
#endif
