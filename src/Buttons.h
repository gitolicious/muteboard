#ifndef BUTTONS_H
#define BUTTONS_H

#include <common.h>
#include <ArduinoHandler.h>
#include <Keyboard.h>

class Buttons : public ArduinoHandler
{
private:
    Keyboard _keyboard;

public:
    Buttons(Keyboard &keyboard)
    {
        className = __func__;
        _keyboard = keyboard;
    };
    void setup();
    void loop();
};

#endif