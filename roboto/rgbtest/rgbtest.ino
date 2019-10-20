#include <Wire.h>
#include "Adafruit_TCS34725.h"
   
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();
 
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
 
void setup(void) {
  Serial.begin(9600);
  
  if (!tcs.begin()) 
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
 
}
 
void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;
  
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  Serial.print(colorTemp, DEC);
  Serial.print(",");  
  Serial.print(lux, DEC);
  Serial.print(",");  
  Serial.print(r, DEC);
  Serial.print(",");
  Serial.print(g, DEC);
  Serial.print(",");  
  Serial.print(b, DEC);
  Serial.print(",");  
  Serial.println(c, DEC);
  delay(50);
}
