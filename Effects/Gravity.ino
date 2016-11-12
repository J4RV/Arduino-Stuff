#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// x=0; v=12; a=-0.6 :: Para que el punto llegue hasta el led 60 en t=10.
float x = 0;
float v = 12;
float a = -0.6;
void Gravity(){
  for(float t = 0; t < 20; t+=0.06){
    int pos = CalcPosition(t);
    strip.setPixelColor(pos, 255, 220, 225);
    strip.show();
    //Haciendo que el color rojo y amarillo tengan suavizado, conseguimos un bonico efecto de fuego.
    Smooth(0.95,0.8,0);
  }
}

int CalcPosition(float t){
  float res = x + (t*v) + (t*t*a);
  return (int) res;
}

