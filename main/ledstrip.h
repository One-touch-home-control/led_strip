#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include "Arduino.h"
#include <FastLED.h>

#define LED_PIN     8  // 스트립 핀번호
#define NUM_LEDS    20 // 스트립 길이
#define BRIGHTNESS  20 // 밝기

void FillLEDsFromPaletteColors(uint8_t colorIndex);
void SetupAllColor(CRGB color);
void led_push_location_color(CRGB in_color, char *arr[]);
void led_push_all_color(CRGB in_color);
void led_init();
#endif
