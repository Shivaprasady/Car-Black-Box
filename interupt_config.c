/*
 * File:   interupt_config.c
 * Author: shiva
 *
 * Created on 22 March, 2024, 10:14 AM
 */


#include <xc.h>

#include"BlackBox.h"

void init_timer()
{
    // interupt
    
    GIE = 1;
    PEIE = 1;
    
    TMR0IE = 1;
    TMR0IF = 0;
    
    
    //timer0
    
    TMR0 = 6;
    TMR0ON = 1;
    T08BIT = 1;
    T0CS = 0;
    PSA = 1;
    
}
