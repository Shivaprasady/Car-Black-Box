/*
 * File:   init_adc.c
 * Author: shiva
 *
 * Created on 12 April, 2024, 8:06 AM
 */


#include <xc.h>
#include"BlackBox.h"

void init_adc()
{
    //ADCON0    
    ADON = 1;
    
    //ADCON1
    
    VCFG1 = 0;
    VCFG0 = 0;
    
    PCFG3 = 1;
    PCFG2 = 0;
    PCFG1 = 1;
    PCFG0 = 0;
    
    //ADCON2
    
    ADFM = 1;
    
    ADCS2 = 0;
    ADCS1 = 1;
    ADCS0 = 0;
    
    ACQT2 = 1;
    ACQT2 = 0;
    ACQT2 = 0;
    
}


unsigned short read_adc(unsigned char channel)
{
    ADCON0 = (ADCON0 & 0xC3) | (channel << 2);
    
    GO = 1;
    while(GO);
    
    return ((ADRESH & 0x03) << 8) | ADRESL;
}
