/*
 * File:   write_password.c
 * Author: shiva
 *
 * Created on 17 May, 2024, 11:58 AM
 */


#include <xc.h>
#include"BlackBox.h"

void write_original_password(unsigned char *write_password)
{
    unsigned char write_address = 0x65;
    for(int i = 0 ; i < 4 ; i++)
    {
        write_24c02(write_address++,write_password[i]);
    }
}
