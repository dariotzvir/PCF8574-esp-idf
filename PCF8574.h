//
//    FILE: PCF8574.h
//  AUTHOR: Rob Tillaart
//    DATE: 02-febr-2013
// VERSION: 0.3.5
// PURPOSE: Arduino library for PCF8574 - 8 channel I2C IO expander
//     URL: https://github.com/RobTillaart/PCF8574
//          http://forum.arduino.cc/index.php?topic=184800
//    FORK: Tzvir Darío

#ifndef PCF8574_INITIAL_VALUE
#define PCF8574_INITIAL_VALUE       0xFF

#define PCF8574_OK                  0x00
#define PCF8574_PIN_ERROR           0x81
#define PCF8574_I2C_ERROR           0x82
#define PCF8574_TIMEOUT_MS 50

#include <stdio.h>
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "sdkconfig.h"
class PCF8574
{
public:
    PCF8574(const uint8_t deviceAddress, const i2c_port_t port);


    bool    begin(const i2c_config_t i2c_conf, uint8_t value);
    bool    begin(uint8_t value);
    bool    isConnected();


    // note: setting the address corrupt internal buffer values
    // a read8() / write8() call updates them.
    bool    setAddress(const uint8_t deviceAddress);
    uint8_t getAddress();  


    uint8_t read8();
    uint8_t read(const uint8_t pin);
    uint8_t value() const { return _dataIn; };


    void    write8(const uint8_t value);
    void    write(const uint8_t pin, const uint8_t value);
    uint8_t valueOut() const { return _dataOut; }


    //added 0.1.07/08 Septillion
    uint8_t readButton8()  { return PCF8574::readButton8(_buttonMask); }
    uint8_t readButton8(const uint8_t mask);
    uint8_t readButton(const uint8_t pin);
    void    setButtonMask(const uint8_t mask) { _buttonMask = mask; };
    uint8_t getButtonMask() { return _buttonMask; };


    // rotate, shift, toggle, reverse expect all lines are output
    void    toggle(const uint8_t pin);
    void    toggleMask(const uint8_t mask = 0xFF);    // default 0xFF ==> invertAll()
    void    shiftRight(const uint8_t n = 1);
    void    shiftLeft(const uint8_t n = 1);
    void    rotateRight(const uint8_t n = 1);
    void    rotateLeft(const uint8_t n = 1);
    void    reverse();


    void    select(const uint8_t pin);
    void    selectN(const uint8_t pin);
    void    selectNone() { write8(0x00); };
    void    selectAll()  { write8(0xFF); };


    int     lastError();


private:
    uint8_t _address;
    i2c_port_t _port = I2C_NUM_0;
    uint8_t _dataIn;
    uint8_t _dataOut;
    uint8_t _buttonMask;
    int     _error;

    i2c_config_t _i2c_conf;
};

#endif
// -- END OF FILE --

