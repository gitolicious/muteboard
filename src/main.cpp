#include <common.h>

#include <typeinfo>

#include <ArduinoHandler.h>
#include <WifiConnection.h>
#include <Keyboard.h>
#include <WifiWebServer.h>
#include <Buttons.h>

WifiConnection wifi;
Keyboard keyboard;
WifiWebServer wifiWebServer(keyboard);
Buttons buttons(keyboard);

ArduinoHandler *handlers[] = {
    &wifi,
    &keyboard,
    &wifiWebServer,
    &buttons};

void setup()
{
    Serial.begin(115200);

    for (ArduinoHandler *handler : handlers)
    {
        Serial.print("Initializing handler ");
        Serial.println(handler->getClassName());
        handler->setup();
    }

    Serial.println("All handlers set up");
}

void loop()
{
    for (ArduinoHandler *handler : handlers)
        handler->loop();
}
