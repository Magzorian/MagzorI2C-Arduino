#include <Wire.h>
#include <MagzorI2C.h>

//Global Declarations

//MIC board address constants
static const uint8_t DARLINGTON_ARRAY_BOARD_ADDRESS = 0x60;

//MIC objects
I2CDevice_DarlingtonArrayBoard darlingtonarray_board1(DARLINGTON_ARRAY_BOARD_ADDRESS);

//device objects
XTransistor t0 = darlingtonarray_board1.get_XTransistor(0);
XTransistor t1 = darlingtonarray_board1.get_XTransistor(1);
XTransistor t2 = darlingtonarray_board1.get_XTransistor(2);
XTransistor t3 = darlingtonarray_board1.get_XTransistor(3);
XTransistor t4 = darlingtonarray_board1.get_XTransistor(4);
XTransistor t5 = darlingtonarray_board1.get_XTransistor(5);
XTransistor t6 = darlingtonarray_board1.get_XTransistor(6);
XTransistor t7 = darlingtonarray_board1.get_XTransistor(7);

uint8_t reset_pin = 0;
uint8_t interrupt_pin = 2;


void setup() {
  //Wait for MICs to initialize
  delay(1500);

  Serial.begin(9600);
  Wire.begin();

  //register reset and interrupt pin
  MagzorI2C::setup(reset_pin, interrupt_pin);

  //register MIC boards
  MagzorI2C::register_i2c_device(darlingtonarray_board1);
  //put your setup code here, to run once:

}



void loop() {
  //Put your main code here, to run repeatedly:
  t0.enable();
  delay(1000);
  t0.disable();
  delay(1000);
}
