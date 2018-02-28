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

			void		setPWMOffset( int16_t _PWMOffset ) ;	///< Applys an offset over the speed value of the motor
			void		stop()				const ;									///< Stops the motor by power reduction
			uint8_t getRawPWMDC() const ;									///< Returns the last set speed value without applying the offset
			uint8_t getPWMDC()		const ;									///< Return the effective last set speed value

			virtual void forward( uint8_t PWMDC = 0 ) = 0 ;
			virtual void back( uint8_t PWMDC = 0 )		= 0 ;
			virtual bool isForward() const = 0 ;
			virtual bool isReverse() const = 0 ;
			virtual bool isStopped() const = 0 ;

		protected:

			int16_t PWMOffset; ///< An offset value for the RawPWMDC
			uint8_t enablePin; ///< The MCU pin connected to the H-bridge's ENABLE pin
			uint8_t RawPWMDC;	 ///< The duty-cycle of the PWM signal applied to the enablePin

};
