#include <Wire.h>
#include <MagzorI2C.h>

//Global Declarations

//MIC board address constants
static const uint8_t MOTOR_BOARD_1_ADDRESS = 0x30;

//MIC objects
I2CDevice_MotorBoard motor_board1(MOTOR_BOARD_1_ADDRESS);

//device objects

// connector 0 on Magzor MIC: 2x DC Motor board #1
XMotor motor1 = motor_board1.get_XMotor(0);
// connector 1 on Magzor MIC: 2x DC Motor board #1
XMotor motor2 = motor_board1.get_XMotor(1);

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
  MagzorI2C::register_i2c_device(motor_board1);
  //put your setup code here, to run once:

}



void loop() {
  //Put your main code here, to run repeatedly:
  for (uint8_t i = 0; i < 255; ++i) {
    motor1.set_speed(i);
    delay(10);
  }
  for (uint8_t i = 255; i > 0; --i) {
    motor1.set_speed(i);
    delay(10);
  }
  motor1.set_direction(XMotor::FLIP);
}
