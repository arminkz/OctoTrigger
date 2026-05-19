#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("OctoTrigger", "arminkz", 100);

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
}

void loop() {
  if (!bleKeyboard.isConnected()) {
    delay(500);
    return;
  }

  if (Serial.available() > 0) { 
    char c = Serial.read();
    if (c == 'w') {
      bleKeyboard.press(KEY_MEDIA_VOLUME_UP);
      delay(100);
      bleKeyboard.release(KEY_MEDIA_VOLUME_UP);
    }
    if (c == 's') {
      bleKeyboard.press(KEY_MEDIA_VOLUME_DOWN);
      delay(100);
      bleKeyboard.release(KEY_MEDIA_VOLUME_DOWN);
    }
    if (c == 'a') {
      bleKeyboard.press(KEY_MEDIA_PREVIOUS_TRACK);
      delay(100);
      bleKeyboard.release(KEY_MEDIA_PREVIOUS_TRACK);
    }
    if (c == 'd') {
      bleKeyboard.press(KEY_MEDIA_NEXT_TRACK);
      delay(100);
      bleKeyboard.release(KEY_MEDIA_NEXT_TRACK);
    }
  }

  delay(10);
}