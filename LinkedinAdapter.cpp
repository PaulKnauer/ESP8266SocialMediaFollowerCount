#include "LinkedinAdapter.h"

/*
 * 
 */
LinkedinAdapter::LinkedinAdapter(LedDisplay *display, WiFiClientSecure client) {
  this->display = display;
}

/*
 * 
 */
void LinkedinAdapter::displayFollowerCount() {
  display->showNumber(5678);
}

