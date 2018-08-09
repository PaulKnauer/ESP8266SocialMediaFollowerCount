#include "ConfigFile.h"

/*
 * 
 */
ConfigFile::ConfigFile() {
  File configFile = SPIFFS.open("/counterConfig.json", "r");
  size_t size = configFile.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFile.readBytes(buf.get(), size);
  StaticJsonBuffer<200> jsonBuffer;
  json = jsonBuffer.parseObject(buf.get());
}

/*
 * 
 */
bool ConfigFile::saveConfig() {
  StaticJsonBuffer<200> jsonBuffer;
  json = jsonBuffer.createObject();

  File configFile = SPIFFS.open("/counterConfig.json", "w");
  if (!configFile) {
    return false;
  }

  json.printTo(configFile);
  return true;
}

/*
 * 
 */
void ConfigFile::setValue(String key, String value) {
  json[key] = value;
}

/*
 * 
 */
String ConfigFile::getValue(String key) {
  return json[key].as<String>();
}

