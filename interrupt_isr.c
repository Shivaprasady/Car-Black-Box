/*
 * File:   interrupt_isr.c
 * Author: shiva
 *
 * Created on 22 March, 2024, 10:16 AM
 */


#include <xc.h>
#include"BlackBox.h"

void __interrupt() isr() {

    
    //Timer interrupt
    if (TMR0IF) {
        TMR0 = TMR0 + 8;

        
        if (wait1++ == 20000) {
            wait1 = 0;
            if(main_flag == 1 && key == 0xFF && blocked != 1)
            {
                wait++;
            }
            else{
                wait = 0;
            }
        }
        if (attempt <= '1' && count++ == 20000) {
                count = 0;
                sec--;
                
        }
        TMR0IF = 0;
    }
    
    // Interrupt by UART
    if (RCIF == 1)
    {
        if (OERR == 1)
            OERR = 0;
        
        ch = RCREG;
        
        RCIF = 0;
    }


}
