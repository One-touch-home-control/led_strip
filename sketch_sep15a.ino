#include "ledstrip.h"

void setup()
{
  Serial.begin(9600);
  led_init();
}

void loop()
{
  led_push_all_color(CRGB::Blue);
  //  delay(1000);
  //  led_push_all_color(CRGB::Red);
  //  delay(1000);
  //  led_push_all_color(CRGB::Green);
  //  delay(1000);
  //  led_push_all_color(CRGB::White);
  //  delay(1000);
  //  led_push_all_color(CRGB::Black);
  //  delay(1000);
  //  led_push_all_color(CRGB::Brown);
  //  delay(1000);
  //  led_push_all_color(CRGB::Yellow);
  //  delay(1000);
  //  led_push_all_color(CRGB::Purple);
  delay(1000);

}
