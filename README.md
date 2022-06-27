# PCF8574-esp-idf

It's a fork from RobTillaart's Arduino library for esp-idf it continues being in C++ the changes made are only for
the specific i2c hal of the framework.

# Differences with the original library

Instead of passing the Wire object found in Arduino in the constructor you pass the number of i2c interface.
The begin methods accept either an i2c_config_t struct in order to initialize the i2c driver in it's own or no struct,
in that case it assumes the driver has been already initialized.