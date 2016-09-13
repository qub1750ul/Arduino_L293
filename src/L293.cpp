#include "L293.h"

//Definition of the methods of the class L293_standalone
//Definition of the constructors

L293_standalone::L293_standalone(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _backPin)
{
  enablePin = _enablePin;
  forwardPin = _forwardPin;
  reversePin = _backPin;
  
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
  
  speedOffset = 0;
}

L293_standalone::L293_standalone(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _backPin, int16_t _speedOffset)
{
  enablePin = _enablePin;
  forwardPin = _forwardPin;
  reversePin = _backPin;
  
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
  
  speedOffset = _speedOffset;
}

//Definitions of the PUBLIC methods

void L293_standalone::forward(uint8_t _pwm)
{
  this->stop();
  digitalWrite(forwardPin, HIGH);
  analogWrite(enablePin, getSpeedWithOffset(_pwm));
}

void L293_standalone::back(uint8_t _pwm)
{
  this->stop();
  digitalWrite(reversePin, HIGH);
  analogWrite(enablePin, getSpeedWithOffset(_pwm));
}

void L293_standalone::stop()
{
  analogWrite(enablePin, 0);
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
}

void L293_standalone::setSpeedOffset(int16_t _speedOffset)
{ 
  speedOffset = _speedOffset;
}

//Definitions of the PROTECTED methods

uint8_t L293_standalone::getSpeedWithOffset(uint8_t _pwm)
{
	if( ( _pwm + speedOffset ) > 255 ) return 255;
	else if( ( _pwm + speedOffset ) < 0 ) return 0;
	else return _pwm + speedOffset;
}

//Definition of the methods of the class L293_twoWire
//Definition of the constructors

L293_twoWire::L293_twoWire(uint8_t _enablePin, uint8_t _directionPin)
{
  enablePin = _enablePin;
  directionPin = _directionPin;
  
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  
  speedOffset = 0;
}

L293_twoWire::L293_twoWire(uint8_t _enablePin, uint8_t _directionPin, int16_t _speedOffset)
{
  enablePin = _enablePin;
  directionPin = _directionPin;
  
  pinMode(enablePin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  
  speedOffset = _speedOffset;
}

//Definition of the PUBLIC methods

void L293_twoWire::forward(uint8_t _pwm)
{
  digitalWrite(directionPin, HIGH);
  analogWrite(enablePin, getSpeedWithOffset(_pwm));
}

void L293_twoWire::back(uint8_t _pwm)
{
  digitalWrite(directionPin, LOW);
  analogWrite(enablePin, getSpeedWithOffset(_pwm));
}

void L293_twoWire::stop()
{
  analogWrite(enablePin, 0);
}
