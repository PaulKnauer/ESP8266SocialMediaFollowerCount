#include "FacebookAdapter.h"

/*
 * 
 */
FacebookAdapter::FacebookAdapter(LedDisplay *display, WiFiClientSecure client, ConfigFile *configFile) {
  this->display = display;
  this->configFile = configFile;
  api = new FacebookApi(client, facebookAccessToken);
}

/*
 * 
 */
void FacebookAdapter::displayFollowerCount() {
//  display->showNumber(api->getTotalFriends());
  display->showNumber(1234);
}

/*
 * 
 */
void FacebookAdapter::checkAccessToken() {
  String newToken = api->extendAccessToken(YOUR_APP_ID, YOUR_APP_KEY);
  if (newToken != "") {
    facebookAccessToken = newToken;
    configFile->setValue(FACEBOOK_TOKEN, newToken);
    configFile->saveConfig();
  }
}

