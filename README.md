# L293

Compatible architecture: ALL

##Description

Library that allows to control bidirectional motors using the L293 IC

##Sintax & short command reference

- Creating an istance  

    *L293(pwmPin, forwardPin, backPin);*   
    *L293(pwmPin, forwardPin, backPin, speedOffset);*  
    
    **L293**        : the name of the object  
    **pwmPin**      : the pin that generate the pwm signal used to control the motor speed  
    **forwardPin**  : the digital pin used to tell the motor to go forward  
    **backpin**     : the digital pin used to tell the motor to go reverse  
    **speedOffset** : the offset value applied to the pwm signal value, used to reduce the power given to a motor  
                     (e.g. in a robot two motors must rotate at the same speed, but one is more powerful than other)  

- Moving the motor

  ***L293.forward(speed);***  : makes the motor to go forward, **speed** can be a value between -255 and 255

  ***L293.back(speed);***     : makes the motor to go reverse, **speed** can be a value between -255 and 255

  ***L293.stop();***          : stops the motor

  ***L293.setSpeedOffset(speedOffset);*** : Used to set a new speed offset value after the creation of the istance

##About the author & license info

Created by ***Giuseppe Masino, 28 may 2016***
Author URL: http://www.facebook.com/peppe.masino1

This library and the relative example files are released under the license
**CreativeCommons Attribution-ShareAlike 4.0 International

License info: http://creativecommons.org/licenses/by-sa/4.0/