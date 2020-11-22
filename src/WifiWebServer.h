#ifndef WIFI_WEB_SERVER_H
#define WIFI_WEB_SERVER_H

#include <common.h>
#include <ArduinoHandler.h>
#include <Keyboard.h>

class WifiWebServer : public ArduinoHandler
{
private:
    Keyboard _keyboard;

public:
    WifiWebServer(Keyboard &keyboard)
    {
        className = __func__;
        _keyboard = keyboard;
    };
    void setup();
    void loop();
};

#endif