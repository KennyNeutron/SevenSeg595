#ifndef SEVENSEG595_H
#define SEVENSEG595_H

#include "Arduino.h"

class SevenSeg595
{
public:
    SevenSeg595();
    void begin(uint8_t dat_Pin, uint8_t clk_Pin, uint8_t lat_Pin, uint8_t oe_Pin, bool AnodeCathode);
    void OneDigit(uint8_t DigitToDisplay, bool Dot);
    void UpdateDisplay();

private:
    void regData(uint8_t DataToReg);
    void dataLatch();

    uint8_t dataPin, clockPin, latchPin, OutputEnablePin;
    bool commonAnodeCathode = false; // True = CA | False = CC

    const uint8_t binCA[20] = {
        0b00000011, // Display 0 on the SevenSegment CA
        0b10011111, // Display 1 on the SevenSegment CA
        0b00100101, // Display 2 on the SevenSegment CA
        0b00001101, // Display 3 on the SevenSegment CA
        0b10011001, // Display 4 on the SevenSegment CA
        0b01001001, // Display 5 on the SevenSegment CA
        0b01000001, // Display 6 on the SevenSegment CA
        0b00011111, // Display 7 on the SevenSegment CA
        0b00000001, // Display 8 on the SevenSegment CA
        0b00001001, // Display 9 on the SevenSegment CA
        0b00000010, // Display 0 with dot on the SevenSegment CA
        0b10011110, // Display 1 with dot on the on the SevenSegment CA
        0b00100100, // Display 2 with dot on the on the SevenSegment CA
        0b00001100, // Display 3 with dot on the on the SevenSegment CA
        0b10011000, // Display 4 with dot on the on the SevenSegment CA
        0b01001000, // Display 5 with dot on the on the SevenSegment CA
        0b01000000, // Display 6 with dot on the on the SevenSegment CA
        0b00011110, // Display 7 with dot on the on the SevenSegment CA
        0b00000000, // Display 8 with dot on the on the SevenSegment CA
        0b00001000  // Display 9 with dot on the on the SevenSegment CA
    };

    const uint8_t binCC[20] = {
        0b11111100, // Display 0 on the SevenSegment CC
        0b01100000, // Display 1 on the SevenSegment CC
        0b11011010, // Display 2 on the SevenSegment CC
        0b11110010, // Display 3 on the SevenSegment CC
        0b01100110, // Display 4 on the SevenSegment CC
        0b10110110, // Display 5 on the SevenSegment CC
        0b10111110, // Display 6 on the SevenSegment CC
        0b11100000, // Display 7 on the SevenSegment CC
        0b11111110, // Display 8 on the SevenSegment CC
        0b11110110, // Display 9 on the SevenSegment CC

        0b11111101, // Display 0 with dot on the SevenSegment CC
        0b01100001, // Display 1 with dot on the SevenSegment CC
        0b11011011, // Display 2 with dot on the SevenSegment CC
        0b11110011, // Display 3 with dot on the SevenSegment CC
        0b01100111, // Display 4 with dot on the SevenSegment CC
        0b10110111, // Display 5 with dot on the SevenSegment CC
        0b10111111, // Display 6 with dot on the SevenSegment CC
        0b11100001, // Display 7 with dot on the SevenSegment CC
        0b11111111, // Display 8 with dot on the SevenSegment CC
        0b11110111  // Display 9 with dot on the SevenSegment CC
    };
};

#endif