/*
 * File:   main.c
 * Author: shiva
 *
 * Created on 18 April, 2024, 8:40 AM
 */


#include <xc.h>
#include"BlackBox.h"

void init_config() {
    init_clcd();
    init_adc();
    init_matrix_keypad();
    init_timer();
    
    //time
    init_i2c();
	init_ds1307();
}



void main(void) {
    
    init_config();
    
    write_original_password(original_password);
    
    while (1) {
        
        key = read_switches(STATE_CHANGE);
        
        
        while(key == 11)
        {
            key = read_switches(LEVEL);
            if(delay11++ == 50000)
            {
                key = 13;
                delay11 = 0;
                break;
            }
        }
        if(delay11 < 50000 && delay11 > 0)
        {
            key = 11;
            delay11 = 0;
        }
        while(key == 12)
        {
            key = read_switches(LEVEL);
            if(delay12++ == 50000)
            {
                key = 14;
                delay12 = 0;
                break;
            }
        }
        if(delay12 < 50000 && delay12 > 0)
        {
            key = 12;
            delay12 = 0;
        }
        
        
        if(wait >= 4)
        {
            main_flag = 0;
            index = 0;
            i = 0;
            user_password[4] = 0;
        }
        if(main_flag == 0)
        {
            dashboard();
        }
        if(main_flag == 1)
        {
            password();
        }
        if(main_flag == 2)
        {
            main_menu();
        }
            
        if(main_flag == 0 && key != 0xFF)
        {
            no_of_EV++;
            store_logs();
            if(key == 3)
            {
                while(1);
            }
            if(view_logs_flag == 1)
            {
                view_logs_flag = 0;
            }
        }
    }
    return;
}
