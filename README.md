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

[![mxUnifiedIO library set illustration](https://github.com/maxint-rd/mxUnifiedIO/blob/master/documentation/libraries.png)]

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


Code examples
=============
Each library comes with well commented and easy to read examples. It's easiest to
start with the Blink examples. Typically you first include the required header files:
```c++
#include <mxUnifiedPCF8574.h>     // implies inclusion of <mxUnifiedIO.h>
#include <mxUnifiedPCD8544.h>
```

Then you can instantiate the required library objects:
```c++
mxUnifiedPCF8574 unio = mxUnifiedPCF8574(0x27, 2, 0);                // on ESP8266 you can other pins
mxUnifiedPCD8544 display = mxUnifiedPCD8544(&unio, 7, 6, 5, 4, 2);   // best pins for the LCD expander
```

In your setup() function you call the required begin() methods:
```c++
void setup()
{
  unio.begin();     // initialize the I2C connection with default I2C speed. 
  display.begin();  // regular begin() using default settings

  // show some text
  display.setContrast(50);
  display.clearDisplay();   // clears the screen and buffer
  display.println("Hello");
  display.display();
}
```

In your loop() you can do what you want, such as toggle a pin:
```c++
void loop()
{
  display.invertDisplay(true);
  unio.digitalWrite(0, HIGH);
  delay(1000); 
  display.invertDisplay(false);
  unio.digitalWrite(0, LOW);
  delay(1000); 
}
```


Adding device specific libraries
================================
To make a library that uses mxUnifiedIO from an existing library is relatively
easy. Take a look at the Nokia 5510 library which is derived from the Adafruit GFX
library: https://github.com/maxint-rd/mxUnifiedPCD8544_Nokia_5110_LCD
For many libraries replacing the digitalWrite() call is sufficient.
For end-users it can be handy to encapsulate the library in a class.
Per convention the pin definition is done in the contstructor, whereas the begin()
method can be used to set specific initialisation parameters. The first parameter
of the constructor should be a reference to the mxUnifiedIO expander object. The
other parameters define the required (expanded) pins. (See example code above).

BTW: if you have implemented your own device library, please let me know, so I can
mention it in the documentation.
