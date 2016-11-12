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
    Smooth();
  }
}

int CalcPosition(float t){
  float res = x + (t*v) + (t*t*a);
  return (int) res;
}

void Smooth(){
  for(int i = 0; i<NUMLEDS; i++){
    SmoothPixel(i, 0.95, 0.9, 0);
  }
}

void SmoothPixel(int i, float r, float g, float b){
  long lngRGB = strip.getPixelColor(i);
  
  uint8_t u8R = (uint8_t)((lngRGB >> 16) & 0xff),
  u8G = (uint8_t)((lngRGB >> 8) & 0xff),
  u8B = (uint8_t)(lngRGB & 0xff);
  
  strip.setPixelColor(i, u8R*r, u8G*g, u8B*b);
}
