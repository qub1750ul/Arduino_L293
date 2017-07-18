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

			L293_twoWire( uint8_t _enablePin, uint8_t _directionPin, int16_t _PWMOffset = 0 );

			virtual void forward( uint8_t _PWMDC );	///< Makes the motor to go forward and sets a new speed value
			virtual void forward();									///< Makes the motor to go forward
			virtual void back( uint8_t _PWMDC );		///< Makes the motor to go reverse and sets a new speed value
			virtual void back();										///< Makes the motor to go reverse
			virtual bool getDirection();						///< Tells the current direction of the motor
			virtual bool isForward();								///< Tells the information about the motor that the name says
			virtual bool isReverse();								///< Tells the information about the motor that the name says
			virtual bool isStopped();								///< Tells the information about the motor that the name says

		private:

			uint8_t directionPin;	///< The MCU pin connected to the circuit's direction control input

	};
