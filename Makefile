# Project:		LiquidCrystal_I2C
# Project description:	LiquidCrystal Arduino/WiringPi library for I2C LCD displays
# Author:		Jiří Vavřík
# Date:			9. 5. 2017

CC=g++
I2C=./LiquidCrystal_I2C
EXE=out
NAME=hello
FILENAME=hello.cpp

$(NAME): $(FILENAME) $(I2C)/LiquidCrystal_I2C.h $(I2C)/LiquidCrystal_I2C.cpp $(I2C)/Print_rpi.h $(I2C)/Print_rpi.cpp $(I2C)/Printable.h
	$(CC) $(FILENAME) -o $(EXE) -I$(I2C) -lwiringPi -DWIRINGPI $(I2C)/Print_rpi.cpp $(I2C)/LiquidCrystal_I2C.cpp
