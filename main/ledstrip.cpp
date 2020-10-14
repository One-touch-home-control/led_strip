#include "ledstrip.h"
#include <FastLED.h>   // 온라인으로 다운바람

#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[255];

#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
CRGBPalette16 usepalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void FillLEDsFromPaletteColors(uint8_t colorIndex) // 컬러 집어넣기
{
  uint8_t brightness = 255;

  for (int i = 0; i < 255; i++) {
    if(i == 2) 
    {
      fill_solid(usepalette, 16, CRGB::White);
      leds[i] = ColorFromPalette(usepalette, colorIndex, brightness, currentBlending);
      continue;
    }
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 1;
  }
}

void FillLEDsFromPaletteColors(uint8_t colorIndex, char *arr[]) // 컬러 집어넣기
{
  uint8_t brightness = 255;

  for (int i = 0; i < 255; i++) {
    if(arr[i] == 1)
    {
      fill_solid(usepalette, 16, CRGB::White);
      leds[i] = ColorFromPalette(usepalette, colorIndex, brightness, currentBlending);
      continue;
    }
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 1;
  }
}

void SetupAllColor(CRGB color) // 한 컬러로 다 넣기
{
  fill_solid(currentPalette, 16, color);
//    currentPalette[0] = CRGB::White;
//    currentPalette[12] = CRGB::White;
}

void led_push_location_color(CRGB in_color, char *arr[])
{
  
}

void led_push_all_color(CRGB in_color) // 하나의 컬러만 다 넣어버리기
{
  SetupAllColor(in_color);
  FillLEDsFromPaletteColors(0);
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void led_init() // led스트립 초기화
{
  delay(1000); // power-up safety delay
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, 50).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  currentBlending = LINEARBLEND;
  led_push_all_color(CRGB::Black);
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}
