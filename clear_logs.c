/*
 * File:   clear_logs.c
 * Author: shiva
 *
 * Created on 9 May, 2024, 10:57 AM
 */


#include <xc.h>
#include"BlackBox.h"

void clear_logs()
{
    CLEAR_DISP_SCREEN;
    view_logs_flag = 1;                                                         // instead of clearing EEPROM using flag
    eeprom_address = 0x00;
    clcd_print("CLEAR LOGS", LINE1(0));
    clcd_print("SUCCESSFUL", LINE2(0));
    __delay_ms(3000);
    menu_flag = 0;
    CLEAR_DISP_SCREEN;
}
