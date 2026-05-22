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
    if (c == 'l') {
      // iOS lock screen shortcut: Ctrl+Cmd+Q
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('q');
      delay(100);
      bleKeyboard.releaseAll();
    }
    if (c == 'u') {
      // Unlock: send "u<passcode>\n" over serial, e.g. "u123456"
      String pin = Serial.readStringUntil('\n');
      pin.trim();
      bleKeyboard.write(' ');       // wake the screen
      delay(400);                   // wait for the lock screen
      bleKeyboard.write(' ');       // dummy key: open the passcode entry page
      delay(400);                   // wait for the passcode field
      for (size_t i = 0; i < pin.length(); i++) {
        bleKeyboard.write(pin[i]);
        delay(50);                  // small gap between digits
      }
    }
  }

  
  delay(10);
}