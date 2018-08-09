#include <ESP8266WiFi.h>

#include "UserConfig.h"
#include "ConfigFile.h"
#include "FacebookAdapter.h"
#include "LinkedinAdapter.h"
#include "TwitterAdapter.h"

ConfigFile  *configFile;
FacebookAdapter *facebook;
LinkedinAdapter *linkedin;
TwitterAdapter *twitter;

/*
 * Initialise the application by:
 * 1. Connecting to WiFi.
 * 2. Initialising the SPIFFS config file.
 * 3. Initialising the social media adapters.
 */
void setup() {
  setUpWiFi();
  WiFiClientSecure client;
  configFile = new ConfigFile();
  facebook = new FacebookAdapter(new LedDisplay(FACEBOOK_CLK, FACEBOOK_DIO), client, configFile);
  linkedin = new LinkedinAdapter(new LedDisplay(LINKEDIN_CLK, LINKEDIN_DIO), client);
  twitter = new TwitterAdapter(new LedDisplay(TWITTER_CLK, TWITTER_DIO), client);
}

/*
 * Refresh the follower count.
 */
void loop() {
  facebook->displayFollowerCount();
  delay(200);
  linkedin->displayFollowerCount();
  delay(200);
  twitter->displayFollowerCount();
  delay(DELAY);
}

/*
 * Connect to the local WiFi network.
 */
void setUpWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(100);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
