# Project:				LiquidCrystal_I2C
# Project description:	LiquidCrystal Arduino/WiringPi library for I2C LCD displays
# Date:					3. 2. 2019

#copy this file along with I2C folder with your project, modify names and you can easily compile your projects on Raspberry Pi!

CC=g++
I2C=./LiquidCrystal_I2C
EXE=out
NAME=hello
FILENAME=hello.cpp

$(NAME): $(FILENAME) $(I2C)/LiquidCrystal_I2C.h $(I2C)/LiquidCrystal_I2C.cpp $(I2C)/Print_rpi.h $(I2C)/Print_rpi.cpp $(I2C)/Printable.h
	$(CC) $(FILENAME) -o $(EXE) -I$(I2C) -lwiringPi -DWIRINGPI $(I2C)/Print_rpi.cpp $(I2C)/LiquidCrystal_I2C.cpp
