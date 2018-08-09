#include "LedDisplay.h"

/*
 * 
 */
LedDisplay::LedDisplay(uint8_t clk, uint8_t dio) {
  ledDisplay = new TM1637Display(clk, dio);
  ledDisplay->setBrightness(0xff);
}

/*
 * Displays the number on the LED display.
 */
void LedDisplay::showNumber(int number) {
  ledDisplay->showNumberDec(number, false);
}

