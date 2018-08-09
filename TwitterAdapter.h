#ifndef TwitterAdapter_h
#define TwitterAdapter_h

#include <ESP8266WiFi.h>
#include <TwitterApi.h>

#include "UserConfig.h"
#include "LedDisplay.h"
#include "ConfigFile.h"

/*
 * Provides an adapter for the Twitter API.
 */
class TwitterAdapter {
  public:
    TwitterAdapter(LedDisplay *display, WiFiClientSecure client);
    void displayFollowerCount();
  private:
    LedDisplay *display;
    TwitterApi *api;
    int getTwitterStats(String name);
    bool haveBearerToken;
    unsigned long api_lasttime = 0;
    bool firstTime = true;
};

#endif
