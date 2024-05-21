/*
 * File:   password.c
 * Author: shiva
 *
 * Created on 22 April, 2024, 9:44 AM
 */


#include <xc.h>
#include"BlackBox.h"

void password() {

    if (index < 4) {
        clcd_print(" ENTER PASSWORD ", LINE1(0));
        if (wait1 < 10000) {
            clcd_putch('_', LINE2(i));
        } else {
            clcd_putch(' ', LINE2(i));
            if (wait1 == 1000)
                wait1 = 0;
        }

        if (key != 0xFF) {
            if (key == 11) {
                user_password[index++] = '0';
                clcd_putch('*', LINE2(i++));
            } else if (key == 12) {
                user_password[index++] = '1';
                clcd_putch('*', LINE2(i++));
            }

        }

    } else if (attempt == '1') {

        blocked = 1;
        if (sec != 0) {
            clcd_print("YOU ARE BLOCKED  ", LINE1(0));
            clcd_print("WAIT FOR            ", LINE2(0));

            clcd_putch(((sec / 100) + '0'), LINE2(9));
            clcd_putch((((sec / 10) % 10) + '0'), LINE2(10));
            clcd_putch(((sec % 10) + '0'), LINE2(11));
        } else {
            main_flag = 0;
            blocked = 0;
            sec = 0;
            index = 0;
            attempt = '3';
            CLEAR_DISP_SCREEN;
        }

        //main_flag = 0;

    } else {
        user_password[4] = '\0';
        
        unsigned char flag = 1;
        unsigned char read_password_address = 0x65;
        for(int  i = 0 ; i < 4 ; i++)
        {
            original_password[i] = read_24c02(read_password_address++);
        }
        for(int i = 0 ; i < 4 ; i++)
        {
            if(user_password[i] != original_password[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            CLEAR_DISP_SCREEN;

            main_flag = 2;
            user_password[2] = '1';
            attempt = '3';
            index = 0;
            i = 0;


        } else {
            attempt--;
            clcd_print(" WRONG PASSWORD ", LINE1(0));
            clcd_print("ATTEMPT LEFT ", LINE2(0));
            clcd_putch(attempt, LINE2(13));
            index = 0;
            i = 0;
            for (unsigned long int i = 0; i++ < 500000;);
            clcd_print("                ", LINE2(0));
        }
    }



}

