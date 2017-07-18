#include "L293_base.hpp"

void L293_base :: stop()
	{
		analogWrite( enablePin, 0 );
	}

void L293_base :: setPWMOffset(int16_t _PWMOffset)
	{
		PWMOffset = _PWMOffset;
	}

uint8_t L293_base :: getRawPWMDC()
	{
		return RawPWMDC;
	}

uint8_t L293_base :: getPWMDC()
	{
		// Take the user-specified PWM value and, if it's set, apply the offset value to it
		// make sure that the returned value is within the limits of an unsigned 8-bit integer

		if( ( RawPWMDC + PWMOffset ) > 255 ) return 255;
		if( ( RawPWMDC + PWMOffset ) < 0 ) return 0;
		return RawPWMDC + PWMOffset;
	}
