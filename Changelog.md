# Change Log  
All notable changes to this project will be documented in this file.  

The format is based on [Keep a Changelog](http://keepachangelog.com/)  
and this project adheres to [Semantic Versioning](http://semver.org/).  

[![Keep a Changelog specification badge](https://img.shields.io/badge/Keep%20a%20Changelog%20Specification-1.0.0-orange.svg)](http://keepachangelog.com)
[![Semantic Versioning specification badge](https://img.shields.io/badge/Semantic%20Versioning%20Specification-2.0.0-orange.svg)](http://semver.org)

## [4.0.2] - 2018-07-19 ##

## Fixed ##

- Keyword highlighting for Arduino IDE

## [4.0.1] - 2018-02-28 ##

## Fixed ##

- A bug that prevented the use of the library

## [4.0.0] - 2018-02-18 [YANKED] ##

### Added ###

- Platformio library manager support  

## Changed ##

- Improved code safety and cleaning  

### Removed ###

- The ***getDirection()*** method  

## [3.1.0] - 2017-06-17 ##

### Added ###

- The following methods to detect the motor's status:
	- ***isForceStopped()***  
	- ***isStopped()***  
	- ***isForward()***  
	- ***isReverse()***  
- Better Doxigen-style comments  

### Changed ###

- This changelog format is now based on [Keep a Changelog](http://keepachangelog.com/)  
- Rewrote the changelog to accomplish what about the previous point  
- Renamed the changelog file for the same purpose  
- **Updated the repository URL**  
- Updated **README.md**  
- Made the code more modular and extensible  
- Made a general cleanup of the code
- Merged the examples that share most code  

### Deprecated ###

- The ***getDirection()*** method is now replaced by the methods ***isForward(), isReverse(), isStopped()*** and ***isForceStopped()***  

## [3.0.0] - 2017-01-04 ##

### Added ###

- Now is possible to change the motor direction without affect the current speed using a dedicated method
- A method to get the direction of the motor  
- A method to get the current PWM value  
- A method to **"force stop"** the motor  

### Changed ###

- Updated **README.md**
- Now the class **L293\_standalone** is named **L293**
- Rewrote the code for the **L293** class
- Now the method **setSpeedOffset()** is named **setPWMOffset()**

### Fixed ###

- A bug about the timing when switching a motor from the forward mode to the reverse mode and viceversa, now it is immediate

## [2.0.0] - 2016-10-16 ##

### Added ###

- A new class named **L293\_twoWire**, derived from **L293\_standalone**, that adds support for motor control using only two wires.
- Better comments to the code  
- The file **LICENSE.md**  
- New examples  

### Changed ###

- Corrected some mistakes in **README.md**
- Updated the old examples
- Now the class **L293** is named **L293\_ standalone**
- Now the **speed Offset** can be a value beetween -255 and 255

## [1.0.1] - 2016-08-25 ##

### Removed ###

- Some useless code

### Changed ###

- Updated the repository URL
- Rewrited **README.md**

## [1.0.0] - 2016-08-11 ##

### Added ###

- Unreleased library files
