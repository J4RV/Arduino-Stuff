#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

float x = 0;
float v = 12;
float a = -0.6;
void Gravity(){
  for(float t = 0; t < 20; t+=0.06){
    int pos = CalcPosition(t);
    strip.setPixelColor(pos, 255, 220, 225);
    strip.show();
    Smooth(0.9,0.8,0);
  }
}

int CalcPosition(float t){
  float res = x + (t*v) + (t*t*a);
  return (int) res;
}

