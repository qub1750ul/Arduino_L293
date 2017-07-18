#pragma once

#include "L293_base.hpp"

/**
 * L293
 * This is the class that provides the standard functionality.
 * The hardware abstracted by this class connects to the MCU using three control wires.
 */

class L293 : public L293_base
	{
		public:

			L293( uint8_t _enablePin, uint8_t _forwardPin, uint8_t _reversePin, int16_t _speedOffset = 0 );

			void forceStop( uint16_t handlingTime );	///< Stops the motor by electrically braking it
			bool isForceStopped();										///< Tells the information about the motor that the name says

			virtual void forward( uint8_t _PWMDC );	///< Makes the motor to go forward and sets a new speed value
			virtual void forward();									///< Makes the motor to go forward
			virtual void back( uint8_t _PWMDC );		///< Makes the motor to go reverse and sets a new speed value
			virtual void back();										///< Makes the motor to go reverse
			virtual bool isForward();								///< Tells the information about the motor that the name says
			virtual bool isReverse();								///< Tells the information about the motor that the name says
			virtual bool isStopped();								///< Tells the information about the motor that the name says
			virtual uint8_t getDirection();					///< deprecated

		protected:

			uint8_t forwardPin;	///< The MCU pin connected to one of the H-bridge's inputs
			uint8_t reversePin;	///< The MCU pin connected to the other H-bridge's input
	};
