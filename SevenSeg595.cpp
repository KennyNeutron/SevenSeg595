#include "SevenSeg595.h"

SevenSeg595::SevenSeg595()
{
}

void SevenSeg595::begin(uint8_t dat_Pin, uint8_t clk_Pin, uint8_t lat_Pin, uint8_t oe_Pin, bool AnodeCathode)
{
    dataPin = dat_Pin;
    clockPin = clk_Pin;
    latchPin = lat_Pin;
    OutputEnablePin = oe_Pin;
    commonAnodeCathode = AnodeCathode;

    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(OutputEnablePin, OUTPUT);

    digitalWrite(dataPin, LOW);
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);
    digitalWrite(OutputEnablePin, HIGH);
}

void SevenSeg595::regData(uint8_t DataToReg)
{
    shiftOut(dataPin, clockPin, LSBFIRST, DataToReg);
}

void SevenSeg595::dataLatch()
{
    digitalWrite(OutputEnablePin, HIGH);
    digitalWrite(latchPin, LOW);
    digitalWrite(latchPin, HIGH);
    digitalWrite(OutputEnablePin, LOW);
}

void SevenSeg595::UpdateDisplay()
{
    dataLatch();
}

void SevenSeg595::OneDigit(uint8_t DigitToDisplay, bool Dot)
{
    if (commonAnodeCathode)
    {
        if (Dot)
        {
            regData(binCA[DigitToDisplay + 10]);
        }
        else
        {
            regData(binCA[DigitToDisplay]);
        }
    }
    else
    {
        if (Dot)
        {
            regData(binCC[DigitToDisplay + 10]);
        }
        else
        {
            regData(binCC[DigitToDisplay]);
        }
    }
}