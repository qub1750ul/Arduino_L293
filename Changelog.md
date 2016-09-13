symbols caption:
> \+ added
> \- removed
> = changed/fixed
> \* coming in a future release

Changelog v2.0.0

> = Made updates and corrected some mistakes in **README.md**  
> = Updated **keywords.txt**  
> = Renamed the class **L293** in **L293\_standalone**  
> = Made **virtual** some public methods in the class **L293\_standalone** to allow to redefine them in the class **L293\_twoWire**  
> = Changed the type of the *protected* variable **speedOffset** in the class **L293\_standalone** from **uint8_t** to **int16_t** to allow it to assume values beetween -255 and 255  
> = Changed the type of the **_speedOffset** argument from **uint8_t** to **int16_t** in the class constructors and in the *public* method ***void L293_standalone::setSpeedOffset(int8_t _speedOffset)***  
> = Made minor changes in the ***virtual void L293\_standalone::forward(uint8_t _pwm)*** and the ***virtual void L293\_standalone::forward(uint8_t _pwm)*** methods  
>  
> \+ Added a new class named **L293\_twoWire**, derived from **L293\_standalone**, that adds support for motor control using only two wires. More details in **README.md**  
> \+ Added the *protected* method ***uint8_t getSpeedWithOffset(uint8_t _pwm)*** to the class **L293\_standalone**  
> \+ Added a new constructor to the class **L293\_standalone** that does nothing, necessary to allow the **L293\_twoWire** class to function properly
> \+ Added comments to the code  
> \+ Added the file **LICENSE.md**  
> \+ Added new examples and updated the old ones  

Changelog v1.0.1 :

> \- removed some useless code from "src/L293.cpp"  
>  
> = changed the repository url  
> = completely rewrited README.md  
>  
> \* add a full changelog file updated on every release  

Changelog v1.0.1-transitionUpdate :

> Update that adds minor changes.  
> Necessary to allow the change of the repository URL in the Arduino library manager.  
> For the full changelog view the release v1.0.1  

Changelog v1.0.0

> First release