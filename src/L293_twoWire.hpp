#pragma once

#include "L293_base.hpp"

/**
 * L293_twoWire
 * This is a variant of the standard L293 class.
 * It's designed to accoplish the same result using only two control wires.
 * The hardware abstracted by this class needs to be connected to the MCU using
 * an additional interfacing circuit.
 */

class L293_twoWire : public L293_base
	{
		public:

			L293_twoWire( uint8_t _enablePin, uint8_t _directionPin, int16_t _PWMOffset = 0 ) ;

			void forward( uint8_t _PWMDC = 0 ) override ; ///< Makes the motor to go forward and optionally sets a new speed value
			void back( uint8_t _PWMDC = 0 )		 override ; ///< Makes the motor to go reverse and optionally sets a new speed value
			bool isForward() const override ;
			bool isReverse() const override ;
			bool isStopped() const override ;

		private:

			uint8_t directionPin;	///< The MCU pin connected to the circuit's direction control input

	};
