#ifndef WIFICONNECTIONMANAGER_H
#define WIFICONNECTIONMANAGER_H

#include <WiFi.h>

class WiFiConnectionManager {
private:
    const char* SSID;
    const char* PASS;
    
public:
    WiFiConnectionManager(const char* wifiSSID, const char* wifiPass);
    void connect();
};

#endif
