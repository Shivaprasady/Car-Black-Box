/*
 * File:   store_logs.c
 * Author: shiva
 *
 * Created on 9 May, 2024, 7:38 AM
 */


#include <xc.h>
#include"BlackBox.h"

void store_logs(){
    
    if(eeprom_address > 98)
        eeprom_address = 0x00;
    
    write_24c02(eeprom_address++,time[0]);
    write_24c02(eeprom_address++,time[1]);
    write_24c02(eeprom_address++,time[3]);
    write_24c02(eeprom_address++,time[4]);
    write_24c02(eeprom_address++,time[6]);
    write_24c02(eeprom_address++,time[7]);
    write_24c02(eeprom_address++,ev[gear][0]);
    write_24c02(eeprom_address++,ev[gear][1]);
    write_24c02(eeprom_address++,sp[0]);
    write_24c02(eeprom_address++,sp[1]);
    
}
