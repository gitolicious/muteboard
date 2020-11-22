#ifndef ARDUINO_HANDLER_H
#define ARDUINO_HANDLER_H

class ArduinoHandler
{
protected:
    const char *className;

public:
    ArduinoHandler() { className = __func__; };
    virtual void setup() = 0;
    virtual void loop() = 0;

    const char *getClassName() { return className; }

    virtual ~ArduinoHandler(){};
};

#endif