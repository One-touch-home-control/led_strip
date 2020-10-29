#include <stdio.h>
#include <wiringPi.h>
#include "ledstrip.h"

int arr[NUM_LEDS];

int main()
{
  if(wiringPiSetup() == -1)
	{
		return -1;
	}
  
  led_init();
  
  while(1)
  {
  led_push_all_color(CRGB::Blue);
  delay(1000);
  led_push_all_color(CRGB::Red);
  delay(1000);
  led_push_all_color(CRGB::Green);
  delay(1000);
  led_push_all_color(CRGB::White);
  delay(1000);
//  led_push_all_color(CRGB::Black);
//  delay(1000);
  led_push_all_color(CRGB::Brown);
  delay(1000);
  led_push_all_color(CRGB::Yellow);
  delay(1000);
  led_push_all_color(CRGB::Purple);
  delay(1000);
  }
}


