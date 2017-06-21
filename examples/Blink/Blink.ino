/*
 * mxUnifiedIO Blink
 * 
 * mxUnifiedIO is a set of libraries that implement unified I/O 
 * on various I/O expanders.
 * 
 * This example demonstrates the use of the mxUnifiedIO library.
 * The base class library is only an abstraction of the hardware pins.
 * Normally it is used in conjunction with the child library for
 * the specific I/O expander.
 * 
 * For more information read the documentation.
 * https://github.com/maxint-rd/mxUnifiedIO
 */
#include <mxUnifiedIO.h>            // include the base library
// #include <mxUnified74HC595.h>       // include the i/o expander library

mxUnifiedIO unio = mxUnifiedIO();   // create the object to access the expanded pins
// mxUnified74HC595 unio = mxUnified74HC595();              // 74HC595 expander using hardware SPI pins, no cascading
// mxUnifiedPCF8574 unio = mxUnifiedPCF8574();              // PCF8574 expander using hardware I2C pins



void setup()
{
  Serial.begin(115200);
  delay(100);   // wait for serial to settle (needed to skip ESP8266 startup info)
  Serial.println(F("\n mxUnifiedIO Blink"));

  unio.begin();     // start using the output expander
  // unio.begin(0x27);     // start using the PCF874 I2C output expander on address 0x27

}

void loop()
{
  Serial.print(F("."));
  unio.digitalWrite(1, HIGH);   // set expanded pin 3 high
  delay(250);
  unio.digitalWrite(1, LOW);   // set expanded pin 3 low
  delay(250);
}

