#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <WiFi.h>

class ClientHandler {
private:
    WiFiClient client;
    const char* SERVERIP;
    const int SERVERPORT;

public:
    ClientHandler(const char* ip, int port);
    bool connect();
    void sendDistance(float distance);
    String receiveCommand();
};

#endif
