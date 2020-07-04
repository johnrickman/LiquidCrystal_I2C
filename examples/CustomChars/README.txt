#!/bin/bash

g++ -I ../../ CustomChars.cpp -o customchars -llci2c
typeset -x LD_LIBRARY_PATH=/usr/local/lib
./customchars
