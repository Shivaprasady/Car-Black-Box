/*
 * File:   dashboard.c
 * Author: shiva
 *
 * Created on 18 April, 2024, 8:41 AM
 */


#include <xc.h>
#include"BlackBox.h"


void dashboard() {
    
    if (key == 11 || key == 12) {
        clcd_print("                ", LINE2(0));
            main_flag = 1;
            key = 0;
            //key = 1;
            return;
    }
    
    if (key != 0xFF) {
        if (key == 1 && gear > 1) {
            gear--;
        } else if (key == 2 && gear < 6) {
            gear++;
        }
        if(key == 3)
        {
            clcd_print("C ", LINE2(9));
            return;
        }
    }
    
    adc = read_adc(4);
    temp = adc/10.24;
    
    sp[0] = (temp / 10) + 48;
    sp[1] = (temp % 10) + 48;
    sp[2] = '\0';
    
    clcd_print("TIME     EV  SP", LINE1(0));
    display_time();
    clcd_print(ev[gear], LINE2(9));
    clcd_print(sp, LINE2(13));
}
