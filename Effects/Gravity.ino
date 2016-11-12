#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// x=0; v=12; a=-0.6 :: Para que el punto llegue hasta el led 60 en t=10.
float x = 0;
float v = 12;
float a = -0.6;
void Gravity(uint8_t red, uint8_t green, uint8_t blue, float redsmooth, float greensmooth, float bluesmooth){
  for(float t = 0; t < 20; t+=0.06){
    int pos = CalcPosition(t);
    strip.setPixelColor(pos, red, green, blue);
    strip.show();
    //Haciendo que el color rojo y amarillo tengan suavizado, conseguimos un bonico efecto de fuego.
    Smooth(redsmooth,greensmooth,bluesmooth);
  }
}

int CalcPosition(float t){
  float res = x + (t*v) + (t*t*a);
  return (int) res;
}

