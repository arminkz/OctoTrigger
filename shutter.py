#!/usr/bin/env python3
import serial
import sys

port = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
port.write(b'w')
port.close()
