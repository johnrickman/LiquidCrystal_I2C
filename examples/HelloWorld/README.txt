#!/bin/bash

g++ -I ../../ HelloWorld.cpp -o helloworld -llci2c

# Inspect /sys/class/i2c-dev/ or run "i2cdetect -l" to determine the
# i2c adapter number for the LCD display. These numbers are ephemeral 
# and can change across reboots, so you can't assume anything.
#
# sudo LD_LIBRARY_PATH=/usr/local/lib ./helloworld -a 27 -d 1
