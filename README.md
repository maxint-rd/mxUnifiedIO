# mxUnifiedIO
mxUnifiedIO base library for Arduino. Use device specific drivers with I/O expanders using a unified API.

mxUnifiedIO is a set of libraries for Arduino (IDE version 1.6 and up) that facilitate easy programming of
multiple devices on I/O expanders or shift registers.

Currently the following expanders are supported:
- PCF8574 I2C I/O expander: https://github.com/maxint-rd/mxUnifiedPCF8574
- 74HC595 shift-registers: https://github.com/maxint-rd/mxUnified74HC595

Currently the following device specific libraries are supported:
- Adafruit PCD8544 Nokia 5110 LCD: https://github.com/maxint-rd/mxUnifiedPCD8544_Nokia_5110_LCD

See the device or I/O expander specific documentation for more information on how to use this library.

MCU pin abstraction
===================
The mxUnifiedIO base class provides the basic functionality of the specific expander libraries.
It also provides abstraction of MCU pins, allowing uniform examples for different MCUs and
pin-numbering independant use by device specific libraries.
Note: the current version supports digitalWrite(), digitalRead() and pinMode(). Currently shiftOut()
and PWM using analogWrite() is not implemented.

Using SPI shift-register
========================
The (shared) SPI bus requires three data-lines to connect one or more shift
registers (SS, MOSI and SCK).
On the Arduino UNO, Nano and Pro Mini, the pins for (fast) hardware SPI are
D10, D12 and D13. On the ESP8266 the default SPI pins are GPIO15, GPIO13 and
GPIO14. When using (slower) software SPI others can be selected too.
See https://github.com/maxint-rd/mxUnified74HC595 for more info.


Using I2C I/O expander
======================
The (shared) I2C bus only requires two data-lines (SDA and SCL).
On the Arduino UNO, Nano and Pro Mini, these can be found on pins A4 and A5.
On the ESP8266 the default pins are GPIO4 and GPIO5, but others can be
selected too.
See https://github.com/maxint-rd/mxUnifiedPCF8574 for more info.
