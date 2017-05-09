# Project:		LiquidCrystal_I2C
# Project description:	LiquidCrystal Arduino/WiringPi library for I2C LCD displays
# Author:		Jiří Vavřík
# Date:			9. 5. 2017

CC=g++
I2C_DIRECTORY=./LiquidCrystal_I2C
FLAGS=`sdl2-config --cflags --libs`
EXE=out
FILENAME=main.cpp

$(FILENAME): $(FILENAME) $(I2C_DIRECTORY)/LiquidCrystal_I2C.h $(I2C_DIRECTORY)/LiquidCrystal_I2C.cpp $(I2C_DIRECTORY)/Print_rpi.h $(I2C_DIRECTORY)/Print_rpi.cpp $(I2C_DIRECTORY)/Printable.h
	$(CC) $(FILENAME) -o $(EXE) -I$(I2C_DIRECTORY) -lwiringPi -DWIRINGPI Print_rpi.cpp LiquidCrystal_I2C.cpp
