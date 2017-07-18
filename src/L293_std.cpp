#include "L293_std.hpp"

L293 :: L293( uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin, int16_t _PWMOffset = 0 )
	{
		enablePin = _enablePin;
		forwardPin = _forwardPin;
		reversePin = _reversePin;

		pinMode( enablePin, OUTPUT );
		pinMode( forwardPin, OUTPUT );
		pinMode( reversePin, OUTPUT );

		PWMOffset = _PWMOffset;
	}

void L293 :: forceStop( uint16_t handlingTime )
	{
		if ( (*this).isForward() ) digitalWrite( reversePin, HIGH );
			else if ( (*this).isReverse() ) digitalWrite( forwardPin, HIGH );

		delay( handlingTime );
		(*this).stop();
	}

void L293 :: forward( uint8_t _PWMDC )
	{
		RawPWMDC = _PWMDC;
		(*this).forward();
	}

void L293 :: forward()
	{
		(*this).stop();
		digitalWrite( reversePin, LOW );
		digitalWrite( forwardPin, HIGH );
		analogWrite( enablePin, this->getPWMDC() );
	}

void L293 :: back( uint8_t _PWMDC )
	{
		RawPWMDC = _PWMDC;
		(*this).back();
	}

void L293 :: back()
	{
		(*this).stop();
		digitalWrite( forwardPin, LOW );
		digitalWrite( reversePin, HIGH );
		analogWrite( enablePin, (*this).getPWMDC() );
	}

uint8_t L293 :: getDirection()
	{
		return (*this).isForward() ? 0 :
					 (*this).isReverse() ? 1 :
					 (*this).isForceStopped() ? 2 : 3 ;
	}

bool L293 :: isForward()
	{
		return digitalRead( forwardPin ) && !digitalRead( reversePin );
	}

bool L293 :: isReverse()
	{
		return !digitalRead( forwardPin ) && digitalRead( reversePin );
	}

bool L293 :: isForceStopped()
	{
		return digitalRead( forwardPin ) && digitalRead( reversePin );
	}

bool L293 :: isStopped()
	{
		return !digitalRead( forwardPin ) && !digitalRead( reversePin );
	}
