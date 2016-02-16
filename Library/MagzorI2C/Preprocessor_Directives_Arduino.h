/*
* This file is part of the Magzor I2C Library.
*
* The Magzor I2C Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser  General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* The Magzor I2C Library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser  General Public License for more details.
*
* You should have received a copy of the GNU Lesser  General Public License
* along with the Magzor I2C Library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PREPROCESSOR_DIRECTIVES_ARDUINO_H
#define	PREPROCESSOR_DIRECTIVES_ARDUINO_H

//****DEFINES INCLUDES FOR BOARD****//
// Arduino 1.0 specific - official
#if defined(ARDUINO) && (ARDUINO >= 100) 
#include "Arduino.h"
// Arduino 23 specific - official
#elif defined(ARDUINO) && (ARDUINO < 100) 
#include "WProgram.h"
#else
#error Unsupported Arduino type for Arduino Preprocessor Directive
#endif

//****DEFINES MACRO FOR FLASH STORED DATA****//
#if defined(ARDUINO) & !defined(_SAM3XA_)
#include <avr/pgmspace.h>
#define DECLARE_FLASH_ARRAY const PROGMEM
#else
#define DECLARE_FLASH_ARRAY static const
//#error Unsupported DECLARE_FLASH_ARRAY for Arduino Preprocessor Directive
#endif


//****DEFINES MACRO FOR RETRIVING FLASH STORED DATA***//
#if defined(ARDUINO) & !defined(_SAM3XA_)
#include <avr/pgmspace.h>
#define GET_FLASH_BYTE(a,i) pgm_read_word_near (&a[i])
#else
#define GET_FLASH_BYTE(a,i) (a[i])
//#error Unsupported GET_FLASH_BYTE(a,i) for Arduino Preprocessor Directive
#endif


//****DEFINES MACRO FOR ASSIGN INTERRUPT NUM***//
#define GET_INTERRUPT_NUM(a) digitalPinToInterrupt(a)

//****DEFINES MACRO FOR SELECTING I2C WIRE NUM***//
#if defined(_VARIANT_ARDUINO_DUE_X_)
#define WIRE Wire			//We would like Due to work on Wire1, but for some reason it doesn't currently work.
#else
#define WIRE Wire
#endif

#endif
