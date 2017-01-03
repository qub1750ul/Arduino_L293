/*
 * L293
 * Library for the control of bidirectional motors and not by the integrated circuit L293
 *
 * Created by Giuseppe Masino, 28 may 2016
 * Author URL http://www.facebook.com/peppe.masino1
 * Author email: dev.giuseppemasino@outlook.it
 *
 * This library and the relative example files are released under the license
 * CreativeCommons ShareAlike-Attribution 4.0 International
 *
 * License info: http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#pragma once

#include <Arduino.h>

class L293_twoWire
{
	public:
		
		L293_twoWire() {};
		L293_twoWire(uint8_t _enablePin, uint8_t _forwardPin);
  		L293_twoWire(uint8_t _enablePin, uint8_t _forwardPin, int16_t _PWMOffset);
		
  		void stop();
  		void setPWMOffset(int16_t _PWMOffset);
		uint8_t getRawPWMDC();
		uint8_t getPWMDC();
		
		virtual void forward(uint8_t _PWMDC);
		virtual void forward();		
		virtual void back(uint8_t _PWMDC);
  		virtual void back();
		virtual uint8_t getDirection();
	
	protected:
			
		int16_t PWMOffset = 0;
		uint8_t enablePin, forwardPin, RawPWMDC = 0;
};

class L293 : public L293_twoWire
{
	public:
		
		L293(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin);
  		L293(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin, int16_t _speedOffset);
		
		void forceStop(uint16_t handlingTime);
		
		virtual void forward(uint8_t _PWMDC);
		virtual void forward();		
		virtual void back(uint8_t _PWMDC);
  		virtual void back();
		virtual uint8_t getDirection();
		
	protected:
		
		uint8_t reversePin;
};