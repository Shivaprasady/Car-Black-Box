/*
 * File:   24c02_external_eeprom.c
 * Author: shiva
 *
 * Created on 9 May, 2024, 8:23 AM
 */


#include <xc.h>
#include"BlackBox.h"



void write_24c02(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(EEPROM_WRITE);
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
    __delay_ms(10);
}


unsigned char read_24c02(unsigned char address)
{
	unsigned char data;

	i2c_start();
	i2c_write(EEPROM_WRITE);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(EEPROM_READ);
	data = i2c_read();
	i2c_stop();

	return data;
}