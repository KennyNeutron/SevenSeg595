#include "SevenSeg595.h"

SevenSeg595 ssCA;

uint8_t counter = 0;

void setup() {
  ssCA.begin(8,9,10,11, false);
}

void loop() {
  ssCA.OneDigit(counter, false);
  ssCA.UpdateDisplay();
  delay(1000);
  counter++;
  if(counter>=10){
    counter=0;
  }
}
