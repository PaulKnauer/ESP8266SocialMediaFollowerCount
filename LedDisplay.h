#ifndef LedDisplay_h
#define LedDisplay_h

#include <TM1637Display.h>

/*
 * Provides an adapter for the TM1637 LED seven segment display.
 */
class LedDisplay {
  public:
    LedDisplay(uint8_t clk, uint8_t dio);
    void showNumber(int number);
  private:
    TM1637Display *ledDisplay;
};

#endif
