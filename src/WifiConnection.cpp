// self
#include <WifiConnection.h>

// 3rd party
#include <WiFiManager.h>

WiFiManager wm;

void WifiConnection::setup()
{
  Serial.print("Connecting to WiFi ");
  wm.autoConnect();
}

void WifiConnection::loop()
{
}
