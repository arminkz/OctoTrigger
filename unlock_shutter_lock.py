#!/usr/bin/env python3
import serial
import sys
import time

PASSCODE = "12345" # Change this to your phone's passcode

port = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)

# Unlock the phone
port.write(b'u' + PASSCODE.encode())
time.sleep(5.0)

# Shutter
port.write(b'w')
time.sleep(2.0)

# Lock the phone
port.write(b'l')
port.close()
