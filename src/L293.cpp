#include "L293.h"

L293_twoWire::L293_twoWire(uint8_t _enablePin, uint8_t _forwardPin)
{	
	enablePin = _enablePin;
	forwardPin = _forwardPin;
	
	pinMode(enablePin, OUTPUT);
	pinMode(forwardPin, OUTPUT);
}

L293_twoWire::L293_twoWire(uint8_t _enablePin, uint8_t _forwardPin, int16_t _PWMOffset)
{	
	enablePin = _enablePin;
	forwardPin = _forwardPin;
	
	pinMode(enablePin, OUTPUT);
	pinMode(forwardPin, OUTPUT);
	
	PWMOffset = _PWMOffset;
}

void L293_twoWire::stop() { analogWrite(enablePin, 0); }
void L293_twoWire::setPWMOffset(int16_t _PWMOffset) { PWMOffset = _PWMOffset; }
uint8_t L293_twoWire::getRawPWMDC() { return RawPWMDC; }

uint8_t L293_twoWire::getPWMDC()
{
	// Take the user-specified PWM value and, if it's set, apply the offset value to it
	// make sure that the returned value is within the limits of an unsigned 8-bit integer
	
	if( ( RawPWMDC + PWMOffset ) > 255 ) return 255;
	if( ( RawPWMDC + PWMOffset ) < 0 ) return 0;
	return RawPWMDC + PWMOffset;
}

void L293_twoWire::forward(uint8_t _PWMDC)
{
	RawPWMDC = _PWMDC;
	this->forward();
}

void L293_twoWire::forward()
{
	this->stop();
	digitalWrite(forwardPin, HIGH);
	analogWrite(enablePin, getPWMDC() );
}

void L293_twoWire::back(uint8_t _PWMDC)
{
	RawPWMDC = _PWMDC;
	this->back();
}

void L293_twoWire::back()
{
	this->stop();
	digitalWrite(forwardPin, LOW);
	analogWrite(enablePin, getPWMDC() );
}

uint8_t L293_twoWire::getDirection() { return digitalRead(forwardPin); }


L293::L293(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin)
{
	enablePin = _enablePin;
	forwardPin = _forwardPin;
	reversePin = _reversePin;
	
	pinMode(enablePin, OUTPUT);
	pinMode(forwardPin, OUTPUT);
	pinMode(reversePin, OUTPUT);
}

L293::L293(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin, int16_t _PWMOffset)
{
	enablePin = _enablePin;
	forwardPin = _forwardPin;
	reversePin = _reversePin;
	
	pinMode(enablePin, OUTPUT);
	pinMode(forwardPin, OUTPUT);
	pinMode(reversePin, OUTPUT);
	
	PWMOffset = _PWMOffset;
}

void L293::forceStop(uint16_t handlingTime)
{
	switch( this->getDirection() )
	{
		case 0:
			digitalWrite(reversePin, HIGH);
			break;
			
		case 1:
			digitalWrite(forwardPin, HIGH);
			break;
			
		default: break;
	}
	
	delay(handlingTime);
	this->stop();
}

void L293::forward(uint8_t _PWMDC)
{
	RawPWMDC = _PWMDC;
	this->forward();
}

void L293::forward()
{
	this->stop();
	digitalWrite(reversePin, LOW);
	digitalWrite(forwardPin, HIGH);
	analogWrite(enablePin, this->getPWMDC() );
}

void L293::back(uint8_t _PWMDC)
{
	RawPWMDC = _PWMDC;
	this->back();
}

void L293::back()
{
	this->stop();
	digitalWrite(forwardPin, LOW);
	digitalWrite(reversePin, HIGH);
	analogWrite(enablePin, this->getPWMDC() );
}

uint8_t L293::getDirection()
{
	if( digitalRead(forwardPin) && !digitalRead(reversePin) ) return 0; // forward
	if( !digitalRead(forwardPin) && digitalRead(reversePin) ) return 1; // reverse
	if( digitalRead(forwardPin) && digitalRead(reversePin) ) return 2;	// force stop
	return 3;															// not determinated
}