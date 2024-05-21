/*
 * File:   UART_display.c
 * Author: shiva
 *
 * Created on 10 May, 2024, 7:55 AM
 */


#include <xc.h>
#include"BlackBox.h"

void uart_display() {
    init_uart();

    CLEAR_DISP_SCREEN;
    
    char rom_address;
    puts("DOWNLODED LOGS :\n\r");

    if (no_of_EV <= 10) {
        rom_address = 0x00;
    } else {
        rom_address = eeprom_address;
    }

    for (int i = 0; i < 10 && i < no_of_EV; i++) {
        for (int j = 0; j < 14; j++) {
            if (j == 2 || j == 5) {
                putch(':');
            } else if (j == 8 || j == 11) {
                putch(' ');
            } else {
                putch(read_24c02(rom_address++));
            }
        }
        puts("\n\r");
        if (rom_address > 98) {
            rom_address = 0;
        }
    }
    clcd_print("DOWNLOD LOGS", LINE1(0));
    clcd_print("SUCCESSFUL", LINE2(0));
    for (unsigned long int i = 0; i++ != 500000;);


}