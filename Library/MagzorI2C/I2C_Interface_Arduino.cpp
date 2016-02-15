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


#include "I2C_Interface_Arduino.h"

int I2C_Interface::i2c_write(uint8_t i2c_address, uint8_t* w, uint8_t w_size){
	WIRE.beginTransmission(i2c_address);
	uint8_t write_count = WIRE.write(w, w_size);
	WIRE.endTransmission();
	
	return write_count;
}

int I2C_Interface::i2c_read(uint8_t i2c_address, uint8_t* r, uint8_t r_size){
	uint8_t read_count = 0;
	
	WIRE.requestFrom(i2c_address, r_size);
	
	for(uint8_t i = 0; i < r_size; ++i){
		if(WIRE.available()){
			r[i] = WIRE.read();
			read_count ++;
		}
	}
	
	return read_count;
}

int I2C_Interface::i2c_write_read(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay){

	I2C_Interface::i2c_write(i2c_address, w, w_size);
	delayMicroseconds(microsecond_wr_delay);
	I2C_Interface::i2c_read(i2c_address, r, r_size);

	MLogger::info("WRITING to 0x" + String(i2c_address, HEX) + "(");
	MLogger::info(String(w_size));
	MLogger::info(" bytes) :");
	
	print_array(w, w_size);
	
	MLogger::info("READING from 0x"+ String(i2c_address, HEX) + "(");
	MLogger::info(String(r_size));
	MLogger::info(" bytes) :");

	print_array(r, r_size);

	return 0;
}


void I2C_Interface::print_array(uint8_t* a, uint8_t a_size){
	for(uint8_t i = 0; i < a_size; i++){
		MLogger::info(String(a[i], HEX));
		MLogger::info(" ");
	}
	MLogger::info("\n");
}
