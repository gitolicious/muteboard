// self
#include <Keyboard.h>

// 3rd party
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("MuteBoard", "ESP Keyboard");

void Keyboard::setup()
{
  Serial.println("Starting BLE keyboard");
  bleKeyboard.begin();
}

void Keyboard::loop()
{
}

bool Keyboard::isConnected()
{
  return bleKeyboard.isConnected();
}

bool Keyboard::setBattery(int val)
{
  Serial.println("Setting BLE keyboard battery level");
  if (!bleKeyboard.isConnected())
    return false;
  bleKeyboard.setBatteryLevel(val);
  return true;
}

bool Keyboard::sendSpeakerMute()
{
  Serial.println("Muting speaker");
  if (!bleKeyboard.isConnected())
    return false;
  bleKeyboard.write(KEY_MEDIA_MUTE);
  return true;
}

bool Keyboard::sendMicMute()
{
  Serial.println("Muting mic");
  if (!bleKeyboard.isConnected())
    return false;
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.print("n");
  bleKeyboard.releaseAll();
  return true;
}

bool Keyboard::sendCameraMute()
{
  Serial.println("Muting cam");
  if (!bleKeyboard.isConnected())
    return false;
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.print("o");
  bleKeyboard.releaseAll();
  return true;
}

bool Keyboard::sendTest()
{
  Serial.println("Sending test command...");
  if (!bleKeyboard.isConnected())
    return false;
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.print("n");
  bleKeyboard.releaseAll();
  Serial.println("Done");
  return true;
}
