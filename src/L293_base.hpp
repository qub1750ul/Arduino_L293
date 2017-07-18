#pragma once

#include <Arduino.h>

/**
 * L293_base
 * This is an abstract class that contains all the members that other classes
 * of the library shares in common.
 * So all other classes inherit from this.
 */

class L293_base
	{
		public:

			void stop();															///< Stops the motor by power reduction
			void setPWMOffset( int16_t _PWMOffset );	///< Applys an offset over the speed value of the motor
			uint8_t getRawPWMDC();										///< Returns the last set speed value without applying the offset
			uint8_t getPWMDC();												///< Return the effective last set speed value

			virtual void forward() = 0;								///< Makes the motor to go forward
			virtual void back() = 0;									///< Makes the motor to go reverse
			virtual bool isForward() = 0;							///< Tells the information about the motor that the name says
			virtual bool isReverse() = 0;							///< Tells the information about the motor that the name says
			virtual bool isStopped() = 0;							///< Tells the information about the motor that the name says

		protected:

			int16_t PWMOffset;	///< An offset value for the RawPWMDC
			uint8_t enablePin;	///< The MCU pin connected to the H-bridge's ENABLE pin
			uint8_t RawPWMDC;		///< The duty-cycle of the PWM signal applied to the enablePin

};
