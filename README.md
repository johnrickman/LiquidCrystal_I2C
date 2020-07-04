# LiquidCrystal_I2C

Portable LiquidCrystal C++ library for I2C LCD displays, with implementations
for both Arduino and RPI (RPI should work with any modern Linux device that 
supports I2C).

Arduino Instructions

Copy to the libraries dir of the IDE using standard process. Then load
one of the sketches into the IDE in exampiles directory, compile, burn to
device as usual.

Linux Instructions

Native RPI (Raspbian)

```
$ autoreconf --install
$ ./configure
$ sudo make install
```

The build examples:

```
$ cd examples/CustomChars
```

Follow steps in README.txt (you can execute the README in bash from command
line as well).
