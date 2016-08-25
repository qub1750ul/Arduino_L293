#include <L293.h>

L293::L293(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _backPin)
{
  enablePin = _enablePin;
  forwardPin = _forwardPin;
  reversePin = _backPin;
  
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
  
  speedOffset = 0;
}

L293::L293(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _backPin, uint8_t _speedOffset)
{
  enablePin = _enablePin;
  forwardPin = _forwardPin;
  reversePin = _backPin;
  
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
  
  speedOffset = _speedOffset;
}

void L293::forward(uint8_t _pwm)
{
  this->stop();
  digitalWrite(forwardPin, HIGH);
  analogWrite(enablePin, _pwm + speedOffset);
}

void L293::back(uint8_t _pwm)
{
  this->stop();
  digitalWrite(reversePin, HIGH);
  analogWrite(enablePin, _pwm + speedOffset);
}

void L293::stop()
{
  analogWrite(enablePin, 0);
  digitalWrite(forwardPin, LOW);
}

void L293::setSpeedOffset(uint8_t _speedOffset)
{
  speedOffset = _speedOffset;
}