/*
 * Bidirectional Motor Control
 *
 * Example of using L293 library to control one or more DC Birirectional Motors
 *
 * Created by Giuseppe Masino, 25 may 2016
 * Author URL http://www.facebook.com/peppe.masino1
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/.
 * -----------------------------------------------------------------------------------
 *
 * Things that you need:
 * - Arduino\Genuino MEGA2560 
 *   (any Arduino\Genuino board can be used, the important is that the L293 pin 1 is connected to a PWM-enabled pin of Arduino)
 *   (on the Arduino MEGA2560 all pins from 2 to 13 are PWM-enabled)
 *   (use of pin 13 is discouraged because it can cause issues when the board resets)
 *
 * - L293
 * - A DC Birirectional Motor (max 5V-4mA)
 * - A breadboard
 *
 * The circuit: https://github.com/HackerInside0/Arduino_L293/blob/master/extras/L293_twoWire.svg
 *
 */

//import the library in the sketch
#include <L293.h>

//give a name to the pins that you use
#define speedPin 2   //that is the pin that we use to control the motor's speed
#define directionPin 3 //this is the pin that we use to tell the motor to go forward

//make a new istance of the L293 library and call it "motor"
//then show what are the pins used to control speed, to tell the motor to go forward and to tell the motor to go reverse
L293_twoWire motor(speedPin,directionPin);

void setup()
{
  //nothing to do in setup()
}

void loop()
{
  motor.forward(255);       //set the direction and the speed of the motor
  delay(1000);              //wait for 1 second before doing else
  motor.back(255);          //set a new direction and the speed of the motor
  delay(1000);              //wait for 1 second before doing else
  motor.stop();             //stop the motor
  delay(1000);              //wait for 1 second before doing else
  
  //now the loop restarts
}