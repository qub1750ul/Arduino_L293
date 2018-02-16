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

			inline void forceStop( uint16_t handlingTime );	///< Stops the motor by electrically braking it
			inline bool isForceStopped() const ;						///< Tells the information about the motor that the name says

			inline void forward( uint8_t _PWMDC = 0 ) override ;	///< Makes the motor to go forward and sets a new speed value
			inline void back( uint8_t _PWMDC = 0 )		override ;			///< Makes the motor to go reverse and sets a new speed value
			inline bool isForward() const override ;										///< Tells the information about the motor that the name says
			inline bool isReverse() const override ;										///< Tells the information about the motor that the name says
			inline bool isStopped() const override ;										///< Tells the information about the motor that the name says

		protected:

			uint8_t forwardPin;	///< The MCU pin connected to one of the H-bridge's inputs
			uint8_t reversePin;	///< The MCU pin connected to the other H-bridge's input
	};
