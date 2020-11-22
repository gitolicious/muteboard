#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <ArduinoHandler.h>
#include <common.h>

class Keyboard : public ArduinoHandler
{
public:
    Keyboard(){ className = __func__; };
    void setup();
    void loop();

    bool isConnected();
    bool setBattery(int val);
    bool sendSpeakerMute();
    bool sendMicMute();
    bool sendCameraMute();
    bool sendTest();
};

#endif