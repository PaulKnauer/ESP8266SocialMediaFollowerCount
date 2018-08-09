#ifndef FacebookAdapter_h
#define FacebookAdapter_h

#include <ESP8266WiFi.h>
#include <FacebookApi.h>
#include <ArduinoJson.h>

#include "UserConfig.h"
#include "LedDisplay.h"
#include "ConfigFile.h"

/*
 * 
 */
class FacebookAdapter {
  public:
    FacebookAdapter(LedDisplay *display, WiFiClientSecure client, ConfigFile *configFile);
    void displayFollowerCount();
  private:
    LedDisplay *display;
    ConfigFile *configFile;
    FacebookApi *api;
    String facebookAccessToken = "EAAEfituE4VABALhkRmcNrHtTMmwISK4XXFtOkdsrjkmZAdv5DZBL97NqbJ7PHH9bOf2euoNnTttPAGXCa8ZB2iOMlZBZCgHqJmfh895DW1KiSG4Q6mZCKfP33PvWYCrLpaLvlCZBQgVUh59vp4WPO1qTeNMYoVEvqBYeENrYgcUJFQzKkW2NqW26bhWjJcr1VEZD";
    void checkAccessToken();
};

#endif
