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

#include "MagzorI2C_Arduino.h"

bool MagzorI2C::initialized = false;
uint8_t MagzorI2C::reset_pin = MagzorI2C::UNASSIGNED_PIN;
uint8_t MagzorI2C::interrupt_pin = MagzorI2C::UNASSIGNED_PIN;

void MagzorI2C::init(){
	if(interrupt_pin != UNASSIGNED_PIN){	
		pinMode(interrupt_pin, INPUT);
		attachInterrupt(GET_INTERRUPT_NUM(interrupt_pin), interrupt_callback, FALLING);	
	}
	initialized = true;
}

void MagzorI2C::setup(uint8_t reset_pin, uint8_t interrupt_pin){
	MagzorI2C::reset_pin = reset_pin;
	MagzorI2C::interrupt_pin = interrupt_pin;
	init();
}

void MagzorI2C::interrupt_callback(){
	detachInterrupt(GET_INTERRUPT_NUM(interrupt_pin));
	interrupts();
	
	//Serial.println("MagzorI2C::interrupt_callback");
	MLogger::info("MagzorI2C::interrupt_callback\n");

	bool alerted = false;
	uint8_t count = 0;

	do {
		if (count < CLEAR_MAX_ATTEMPTS) {
			alerted = AlertObserver::alert();
			if (alerted) {
				count = 0;
			}
			count++;
		} else {
			//printf("Attempted to clear interrupt 10 times. Flag pin is stuck!");
			break;
		}
	} while (!digitalRead(interrupt_pin));
	
	pinMode(interrupt_pin, INPUT);
	attachInterrupt(GET_INTERRUPT_NUM(interrupt_pin), interrupt_callback, FALLING);
}

void MagzorI2C::hardware_reset_i2c_devices(){
	if(reset_pin != UNASSIGNED_PIN){
		pinMode(reset_pin, OUTPUT);
		digitalWrite(reset_pin, HIGH);
		delay(100);
		digitalWrite(reset_pin, LOW);
		delay(3000);
	}
}

void MagzorI2C::register_i2c_device(AbstractMagzorI2CDevice* device){
	AlertObserver::register_subject(device);
}

void MagzorI2C::register_i2c_device(AbstractMagzorI2CDevice& device){
	MagzorI2C::register_i2c_device(&device);
}

void MagzorI2C::clear_i2c(){
	
}
