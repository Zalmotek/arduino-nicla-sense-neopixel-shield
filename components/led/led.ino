#include <Adafruit_NeoPixel.h>
#include "Nicla_System.h"

#define PIN         0
#define NUMPIXELS   12 
#define pushButton  11

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500
int randNumber;
void setup() {
  
  pixels.begin();
  pinMode(pushButton, INPUT_PULLUP);
  for(int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
    }
}

void loop() {
  pixels.clear();
  int pushButtonState;
  randNumber = random(0, 12);
  pushButtonState = analogRead(pushButton);
  if(pushButtonState <= 50){
    for(int i=0; i<randNumber; i++) {
      if(i < 3) {
        pixels.setPixelColor(i, pixels.Color(30, 0, 0));
        pixels.show();
        delay(DELAYVAL);
      }
      if(i >=3 && i < 6) {
        pixels.setPixelColor(i, pixels.Color(60, 20, 0));
        pixels.show();
        delay(DELAYVAL);
      }
      if(i >= 6 && i < 9) {
        pixels.setPixelColor(i, pixels.Color(30, 25, 0));
        pixels.show();
        delay(DELAYVAL);
      }
      if(i >= 9 && i < 12) {
        pixels.setPixelColor(i, pixels.Color(0, 30, 0));
        pixels.show();
        delay(DELAYVAL);
      }
      
    } 
  }
  if(pushButtonState >= 50) {
    for(int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
    }
  }
}
