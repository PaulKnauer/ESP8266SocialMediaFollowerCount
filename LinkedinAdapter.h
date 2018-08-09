#ifndef LinkedinAdapter_h
#define LinkedinAdapter_h

#include <ESP8266WiFi.h>

#include "UserConfig.h"
#include "LedDisplay.h"
#include "ConfigFile.h"

/*
 * Provides an adapter for the LinkedIn.
 */
class LinkedinAdapter {
  public:
    LinkedinAdapter(LedDisplay *display, WiFiClientSecure client);
    void displayFollowerCount();
  private:
    LedDisplay *display;
};

#endif
