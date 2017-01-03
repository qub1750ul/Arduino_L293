/*
 * Bidirectional Motor Control
 *
 * Example of using L293 library to control one or more DC Birirectional Motors
 *
 * Created by Giuseppe Masino, 25 may 2016
 * Author URL http://www.facebook.com/peppe.masino1
 * Author email: dev.giuseppemasino@outlook.it
 *
 * This example and the L293 library are released under the license
 * CreativeCommons ShareAlike-Attribution
 *
 * -----------------------------------------------------------------------------------
 *
 * Things that you need:
 * - Arduino\Genuino MEGA2560 
 *   (any Arduino\Genuino board can be used, the important is that the L293 pin 1 is connected to a PWM-enabled pin of Arduino)
 *   (on the Arduino MEGA2560 all pins from 2 to 13 are PWM-enabled)
 *   (use of pin 13 is discouraged because it can cause issues when the board resets)
 *
 * - An L293 IC
 * - A DC Birirectional Motor (max 5V-4mA)
 * - A breadboard
 *
 *
 * The circuit:
 * - Arduino pin 2 -> L293 pin 1
 * - Arduino pin 3 -> L293 pin 2
 * - Arduino pin 4 -> L293 pin 7
 * - Arduino GND -> L293 pin 4, 5
 * - Arduino 5V -> L293 pin 16, 8
 *
 * - L293 pin 3 -> a terminal of the motor
 * - L293 pin 6 -> the other terminal of the motor
 *
 */

//import the library in the sketch
#include <L293.h>

//these are constants and won't change
//give a name to the pins that we use
const int speedPin = 2;  //that is the pin that we use to control the motor's speed
const int forwardPin = 3; //this is the pin that we use to tell the motor to go forward
const int reversePin = 4; //this is the pin that we use to tell the motor to go reverse

//make a new istance of the L293 library and call it "motor"
//then show what are the pins used to control speed, to tell the motor to go forward and to tell the motor to go reverse
L293 motor(speedPin,forwardPin,reversePin);

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