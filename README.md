# L293 #

Compatible architecture: ALL

## Description ##

Library that allows to control bidirectional motors using the L293 IC in two different hardware configurations:

- L293_standalone
- L293_twoWire

### L293_standalone configuration ###

This configuration in intended for use with a standalone L293 IC, using 3 wires for each motor to control ( exclunding the power supply ).
The circuit must be like this:
![L293_standalone HW configuration](https://github.com/HackerInside0/Arduino_L293/blob/master/extras/L293_standalone-HW-conf.png)

### L293_twoWire configuration ###

This configuration is intended for use with a circuit like this:
![L293_twoWire HW configuration](https://github.com/HackerInside0/Arduino_L293/blob/master/extras/L293_twoWire-HW-conf.png)

Where only two wires are used to control the motor: the PWM signal and the direction signal ( excluding the power supply )

## Sintax & short command reference ##
### Reference for the L293_standalone configuration ###

- Creating an istance  

    *L293_standalone motor(pwmPin, forwardPin, backPin);*   
    *L293_standalone motor(pwmPin, forwardPin, backPin, speedOffset);*  
    
    **motor**       : the name of the object  
    **pwmPin**      : the pin that generate the pwm signal used to control the motor speed  
    **forwardPin**  : the digital pin used to tell the motor to go forward  
    **backpin**     : the digital pin used to tell the motor to go reverse  
    **speedOffset** : the offset value applied to the pwm signal value, used to reduce the power given to a motor (can be a value beetween -255 and 255)
                      (e.g. in a robot two motors must rotate at the same speed, but one is more powerful than other)  

### Reference for the L293_twoWire configuration ###

- Creating an istance  

    *L293_twoWire motor(pwmPin, directionPin);*   
    *L293_twoWire motor(pwmPin, directionPin, speedOffset);*  
    
    **motor**        : the name of the object  
    **pwmPin**       : the pin that generate the pwm signal used to control the motor speed  
    **directionPin** : the digital pin used to manage the motor direction  
    **speedOffset**  : the offset value applied to the pwm signal value, used to reduce the power given to a motor (can be a value beetween -255 and 255)
                      (e.g. in a robot two motors must rotate at the same speed, but one is more powerful than other)  

### Common reference ###

- Moving the motor

  ***L293.forward(speed);***  : makes the motor to go forward, **speed** can be a value beetween 0 and 255  
  ***L293.back(speed);***     : makes the motor to go reverse, **speed** can be a value beetween 0 and 255  
  ***L293.stop();***          : stops the motor  
  ***L293.setSpeedOffset(speedOffset);*** : Used to set a new speed offset value after the creation of the istance, **speedOffset** can be a value beetween -255 and 255  

## About the author & license info

Created by ***Giuseppe Masino, 28 may 2016***
Author URL: http://www.facebook.com/peppe.masino1

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work by <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/HackerInside0/Arduino_L293.git" property="cc:attributionName" rel="cc:attributionURL">Giuseppe Masino</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="http://creativecommons.org/ns#" href="https://facebook.com/peppe.masino1" rel="cc:morePermissions">https://facebook.com/peppe.masino1</a>.
