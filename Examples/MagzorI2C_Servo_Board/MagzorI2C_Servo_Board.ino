#include <Wire.h>
#include <MagzorI2C.h>

//Global Declarations

//MIC board address constants
static const uint8_t SERVO_BOARD_1_ADDRESS = 0x20;

//MIC objects
I2CDevice_ServoBoard servo_board1(SERVO_BOARD_1_ADDRESS);

//device objects

// connector 0 on Magzor MIC: 8x Servo board #1
XServo servo1 = servo_board1.get_XServo(0);
// connector 1 on Magzor MIC: 8x Servo board #1
XServo servo2 = servo_board1.get_XServo(1);
// connector 2 on Magzor MIC: 8x Servo board #1
XServo servo3 = servo_board1.get_XServo(2);
// connector 3 on Magzor MIC: 8x Servo board #1
XServo servo4 = servo_board1.get_XServo(3);
// connector 4 on Magzor MIC: 8x Servo board #1
XServo servo5 = servo_board1.get_XServo(4);
// connector 5 on Magzor MIC: 8x Servo board #1
XServo servo6 = servo_board1.get_XServo(5);
// connector 6 on Magzor MIC: 8x Servo board #1
XServo servo7 = servo_board1.get_XServo(6);
// connector 7 on Magzor MIC: 8x Servo board #1
XServo servo8 = servo_board1.get_XServo(7);

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
  MagzorI2C::register_i2c_device(servo_board1);
  //put your setup code here, to run once:

}



void loop() {
  //Put your main code here, to run repeatedly:
  for (uint8_t i = 0; i <= 180; ++i) {
    servo1.write(i);
    delay(25);
  }
  for (uint8_t i = 180; i > 0; --i) {
    servo1.write(i);
    delay(25);
  }
}
