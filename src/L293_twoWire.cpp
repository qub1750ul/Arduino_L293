#include "L293_twoWire.hpp"

L293_twoWire :: L293_twoWire( uint8_t _enablePin, uint8_t _directionPin, int16_t _PWMOffset )
	{
		enablePin = _enablePin;
		directionPin = _directionPin;

		pinMode(enablePin, OUTPUT);
		pinMode(directionPin, OUTPUT);

		PWMOffset = _PWMOffset;
	}

void L293_twoWire :: forward( uint8_t _PWMDC )
	{
		if( _PWMDC ) RawPWMDC = _PWMDC ;

		this->stop();
		digitalWrite( directionPin, HIGH );
		analogWrite( enablePin, this->getPWMDC() );
	}

void L293_twoWire :: back( uint8_t _PWMDC )
	{
		if( _PWMDC ) RawPWMDC = _PWMDC ;

		this->stop();
		digitalWrite( directionPin, LOW );
		analogWrite(enablePin, this->getPWMDC() );
	}

bool L293_twoWire :: isForward() const
	{
		return digitalRead( directionPin );
	}

bool L293_twoWire :: isReverse() const
	{
		return !( this->isForward() ) ;
	}

bool L293_twoWire :: isStopped() const
	{
		return this->getPWMDC() ;
	}
