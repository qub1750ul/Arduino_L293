/*
 * L293
 * Library for the control of bidirectional motors and not by the integrated circuit L293
 *
 * Created by Giuseppe Masino, 28 may 2016
 * Author URL http://www.facebook.com/peppe.masino1
 *
 * This library and the relative example files are released under the license
 * CreativeCommons ShareAlike-Attribution 4.0 International
 *
 * License info: http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef l293_lib
#define l293_lib

#include <Arduino.h>

class L293_standalone
{
	public:
		
		L293_standalone() {};
		L293_standalone(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _backPin);
  		L293_standalone(uint8_t _enablePin, uint8_t _forwardPin, uint8_t _backPin, int16_t _speedOffset);
  		
  		virtual void forward(uint8_t _pwm);
  		virtual void back(uint8_t _pwm);
  		virtual void stop(void);
		
  		void setSpeedOffset(int16_t _speedOffset);
	
	protected:
		
		uint8_t getSpeedWithOffset(uint8_t _pwm);
	
		int16_t speedOffset;
		uint8_t enablePin, forwardPin, reversePin;
};

class L293_twoWire : public L293_standalone
{
	public:
		
		L293_twoWire(uint8_t _enablePin, uint8_t _directionPin);
		L293_twoWire(uint8_t _enablePin, uint8_t _directionPin, int16_t _speedOffset);
		
		virtual void forward(uint8_t _pwm);
		virtual void back(uint8_t _pwm);
		virtual void stop(void);
	
	protected:
		
		uint8_t directionPin;
};

#endif