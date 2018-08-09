#ifndef ConfigFile_h
#define ConfigFile_h

#include <ArduinoJson.h>

#include "FS.h"

/*
 * 
 */
class ConfigFile {
  public:
    ConfigFile();
    bool loadConfig();
    bool saveConfig();
    void setValue(String key, String value);
    String getValue(String key);
  private:
    JsonVariant json;
};

#endif
