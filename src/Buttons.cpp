// self
#include <Buttons.h>

// 3rd party
#include <Bounce2.h>

// button pin numbers
#define BUTTON_PIN_CAM 15
#define BUTTON_PIN_MIC 3
#define BUTTON_PIN_SPEAKER 4
#define BUTTON_PIN_PTT 16

Button buttonCam = Button();
Button buttonMic = Button();
Button buttonSpeaker = Button();
Button buttonPtt = Button();

void Buttons::setup()
{
  Serial.println("Setting up buttons");

  buttonCam.attach(BUTTON_PIN_CAM, INPUT_PULLUP);
  buttonCam.interval(5);
  buttonCam.setPressedState(LOW);

  buttonMic.attach(BUTTON_PIN_MIC, INPUT_PULLUP);
  buttonMic.interval(5);
  buttonMic.setPressedState(LOW);

  buttonSpeaker.attach(BUTTON_PIN_SPEAKER, INPUT_PULLUP);
  buttonSpeaker.interval(5);
  buttonSpeaker.setPressedState(LOW);

  buttonPtt.attach(BUTTON_PIN_PTT, INPUT_PULLUP);
  buttonPtt.interval(5);
  buttonPtt.setPressedState(LOW);
}

void Buttons::loop()
{
  buttonCam.update();
  buttonMic.update();
  buttonSpeaker.update();
  buttonPtt.update();

  if (buttonCam.pressed())
  {
    Serial.println("Cam mute button pressed");
    _keyboard.sendCameraMute();
  }
  if (buttonMic.pressed())
  {
    Serial.println("Mic mute button detected");
    _keyboard.sendMicMute();
  }
  if (buttonSpeaker.pressed())
  {
    Serial.println("Speaker mute button detected");
    _keyboard.sendSpeakerMute();
  }
  if (buttonPtt.pressed())
  {
    Serial.println("PTT button detected");
    _keyboard.sendMicMute();
  }
}
