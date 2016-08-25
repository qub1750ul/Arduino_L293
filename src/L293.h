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

class L293
{
  public:
  
  L293(byte _enablePin, byte _forwardPin, byte _backPin);
  L293(byte _enablePin, byte _forwardPin, byte _backPin, byte _speedOffset);
  
  void forward(byte _pwm);
  void back(byte _pwm);
  void stop(void);
  void setSpeedOffset(byte _speedOffset);
    
  protected:
           
  uint8_t enablePin, forwardPin, reversePin, speedOffset;
};

#endif