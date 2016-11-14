#include <Adafruit_NeoPixel.h>
#include <Math.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// v=12; a=-0.6 :: Para que el punto llegue hasta el led 60 en t=10.
float v = NUMLEDS / 5.0;
float a = -v/20.0;
float d = 0.9;

void ResetIVs(float decay){
  v = NUMLEDS / 5;
  a = -v/20.0;
  d = decay;
}

void Gravity(uint8_t red, uint8_t green, uint8_t blue, float redsmooth, float greensmooth, float bluesmooth){
  int pos = 0;
  for(float t = 0; pos >= 0; t+=0.06){
    pos = CalcPosition(t);
    strip.setPixelColor(pos, red, green, blue);
    strip.show();
    Smooth(redsmooth,greensmooth,bluesmooth);
  }
  v *= d;
}

int CalcPosition(float t){
  float res = (t*v) + (t*t*a);
  return round(res);
}

