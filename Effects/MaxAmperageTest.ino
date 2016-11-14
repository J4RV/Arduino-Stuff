#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

void MaxAmperageTest(int wait){
  strip.setBrightness(255);
  
  for(int i = 0; i < NUMLEDS; i++){
    strip.setPixelColor(i, 255, 255, 255);
    strip.show();
    delay(wait);
  }

  delay(wait * 10);  
  strip.setBrightness(BRIGHTNESS);
}

