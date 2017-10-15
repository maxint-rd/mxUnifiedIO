#ifndef _MXUNIFIEDIO_H
#define _MXUNIFIEDIO_H

//#if !defined(_MXUNIFIEDIO_DEBUG)
//#define _MXUNIFIEDIO_DEBUG 1
//#endif

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
#endif

//#if defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__) || defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny2313__) || defined(__AVR_ATtiny4313__) || defined(__AVR_ATtiny861__)  
// TODO: currently  only tested __AVR_ATtiny85__ using attiny boarddefinitions by David A. Mellis, others might work too.
#if defined(__AVR_ATtiny85__)
	#define MXUNIFIED_ATTINY 85
#endif

class mxUnifiedIO
{
 public:
 	mxUnifiedIO(void); // Constructor

  // This MUST be defined by the subclass:


  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void begin(void);
  virtual uint8_t getNumPins(void);
  virtual void setBit(uint8_t nPin, uint8_t nValue);
  virtual void set8Bits(uint8_t nValue);
  virtual uint8_t getBit(uint8_t nPin);
  virtual uint8_t get8Bits(void);
  virtual void send8Bits(bool fClosedTransmission=true);
  virtual void sendBits(void);
  virtual void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t value);
  virtual void startTransmission(void);
  virtual void endTransmission(void);
 	
 	virtual void digitalWrite(uint8_t nPin, uint8_t nVal);
 	virtual void digitalWrite8(uint8_t nVal);
 	virtual int digitalRead(uint8_t nPin);
 	virtual void pinMode(uint8_t nPin, uint8_t nMode);

 protected:
// 	uint8_t _dataOut;
 	uint32_t _dataOut;		// current version supports max of 32 expanded pins
 	uint8_t _nNumPins;
 	uint8_t _nConstr;

 private:
 	uint8_t _aPins[8];
};

#endif // _MXUNIFIEDIO_H
