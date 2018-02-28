#include "L293_std.hpp"

L293 :: L293( uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin, int16_t _PWMOffset )
	{
		enablePin  = _enablePin;
		forwardPin = _forwardPin;
		reversePin = _reversePin;

		pinMode( enablePin,  OUTPUT );
		pinMode( forwardPin, OUTPUT );
		pinMode( reversePin, OUTPUT );

		PWMOffset = _PWMOffset;
	}

void L293 :: forceStop( uint16_t handlingTime )
	{
		if ( this->isForward() ) digitalWrite( reversePin, HIGH );
			else if ( this->isReverse() ) digitalWrite( forwardPin, HIGH );

		delay( handlingTime );
		this->stop();
	}

void L293 :: forward( uint8_t _PWMDC )
	{
		if( _PWMDC > 0 ) RawPWMDC = _PWMDC;

		this->stop();
		digitalWrite( reversePin, LOW );
		digitalWrite( forwardPin, HIGH );
		analogWrite( enablePin, this->getPWMDC() );
	}

void L293 :: back( uint8_t _PWMDC )
	{
		if( _PWMDC > 0 ) RawPWMDC = _PWMDC;

		this->stop();
		digitalWrite( forwardPin, LOW );
		digitalWrite( reversePin, HIGH );
		analogWrite( enablePin, this->getPWMDC() );
	}

bool L293 :: isForward() const
	{
		return digitalRead( forwardPin ) && !digitalRead( reversePin );
	}

bool L293 :: isReverse() const
	{
		return !digitalRead( forwardPin ) && digitalRead( reversePin );
	}

bool L293 :: isForceStopped() const
	{
		return digitalRead( forwardPin ) && digitalRead( reversePin );
	}

bool L293 :: isStopped() const
	{
		return !digitalRead( forwardPin ) && !digitalRead( reversePin );
	}
