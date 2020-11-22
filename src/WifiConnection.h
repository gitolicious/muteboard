#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

#include <common.h>
#include <ArduinoHandler.h>

class WifiConnection : public ArduinoHandler
{
public:
    WifiConnection() { className = __func__; };
    void setup();
    void loop();
};

#endif