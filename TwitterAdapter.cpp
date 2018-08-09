#include "TwitterAdapter.h"

/*
 * Contructs a TwitterAdapter
 */
TwitterAdapter::TwitterAdapter(LedDisplay *display, WiFiClientSecure client) {
  this->display = display;
  api = new TwitterApi(client);
  api->setBearerToken(TWITTER_BEARER_ACCESS_TOKEN);
  display->showNumber(getTwitterStats(TWITTER_NAME));
}

/*
 * Display the number of Twitter followers.
 */
void TwitterAdapter::displayFollowerCount() {
  if (millis() > (api_lasttime + TWITTER_API_MTBS))  {
    display->showNumber(getTwitterStats(TWITTER_NAME));
    api_lasttime = millis();
  }
}

/*
 * Extract the followers_count from the JSON response.
 */
int TwitterAdapter::getTwitterStats(String name) {
  String responseString = api->getUserStatistics(name);
  DynamicJsonBuffer jsonBuffer;
  JsonObject& response = jsonBuffer.parseObject(responseString);
  if (response.success() && response.containsKey("followers_count")) {
    return response["followers_count"].as<int>();
  } else {
    return 0;
  }
}

