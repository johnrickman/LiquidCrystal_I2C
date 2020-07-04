#!/bin/bash

g++ -I ../../ CustomChars.cpp -o customchars -llci2c
typeset -x LD_LIBRARY_PATH=/usr/local/lib

#Inspect /sys/class/i2c-dev/ or run "i2cdetect -l" to determine the
#i2c adapter number for the LCD display. These numbers are ephemeral 
#and can change across reboots, so you can't assume anything.
#
#ADAPTER=2
#
#./customchars -a $ADAPTER
