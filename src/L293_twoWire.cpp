#include "L293_twoWire.hpp"

L293_twoWire :: L293_twoWire( uint8_t _enablePin, uint8_t _directionPin, int16_t _PWMOffset = 0 )
	{
		enablePin = _enablePin;
		directionPin = _directionPin;

		pinMode(enablePin, OUTPUT);
		pinMode(directionPin, OUTPUT);

		PWMOffset = _PWMOffset;
	}

void L293_twoWire :: forward( uint8_t _PWMDC )
	{
		RawPWMDC = _PWMDC;
		(*this).forward();
	}

void L293_twoWire :: forward()
	{
		(*this).stop();
		digitalWrite( directionPin, HIGH );
		analogWrite( enablePin, (*this).getPWMDC() );
	}

void L293_twoWire :: back( uint8_t _PWMDC )
	{
		RawPWMDC = _PWMDC;
		(*this).back();
	}

void L293_twoWire :: back()
	{
		(*this).stop();
		digitalWrite( directionPin, LOW );
		analogWrite(enablePin, (*this).getPWMDC() );
	}


bool L293_twoWire :: getDirection()
	{
		return digitalRead( directionPin );
	}

bool L293_twoWire :: isForward()
	{
		return digitalRead( directionPin );
	}

bool L293_twoWire :: isReverse()
	{
		return !( (*this).isForward() );
	}

bool L293_twoWire :: isStopped()
	{
		return (*this).getPWMDC() ? 1 : 0 ;
	}
