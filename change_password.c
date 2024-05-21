/*
 * File:   change_password.c
 * Author: shiva
 *
 * Created on 2 May, 2024, 7:38 AM
 */


#include <xc.h>
#include"BlackBox.h"

void change_password() {

    if (index_new < 4) {
        clcd_print("ENTER NEW PASSWD", LINE1(0));
        if (wait1 < 10000) {
            clcd_putch('_', LINE2(i_new));
        } else {
            clcd_putch(' ', LINE2(i_new));
            if (wait1 == 1000)
                wait1 = 0;
        }

        if (key != 0xFF) {
            if (key == 11) {
                new_password[index_new++] = '0';
                clcd_putch('*', LINE2(i_new++));
            } else if (key == 12) {
                new_password[index_new++] = '1';
                clcd_putch('*', LINE2(i_new++));
            }
        }

    } else if (index_conform < 4) {
        if (index_conform == 0 && clear_flag == 1) {
            CLEAR_DISP_SCREEN;
            clear_flag = 0;
        }
        clcd_print("CONFORM PASSWORD", LINE1(0));
        if (index_conform < 4) {
            if (wait1 < 10000) {
                clcd_putch('_', LINE2(i_conform));
            } else {
                clcd_putch(' ', LINE2(i_conform));
                if (wait1 == 1000)
                    wait1 = 0;
            }

            if (key != 0xFF) {
                if (key == 11) {
                    conform_password[index_conform++] = '0';
                    clcd_putch('*', LINE2(i_conform++));
                } else if (key == 12) {
                    conform_password[index_conform++] = '1';
                    clcd_putch('*', LINE2(i_conform++));
                }
            }
        }
    } else {
        if (index_new == 4 && index_conform == 4) {
            new_password[index_new] = '\0';
            conform_password[index_conform] = '\0';
        }


        unsigned char flag = 1;
        for (int i = 0; i < 4; i++) {
            if (new_password[i] != conform_password[i]) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            for (int k = 0; k < 4; k++) {
                original_password[k] = conform_password[k];
            }
            
            write_original_password(original_password);
            
            clcd_print("CHANGE PASSWORD ", LINE1(0));
            clcd_print("SUCCESSFUL", LINE2(0));
            for (unsigned long int i = 0; i++ != 500000;);
            CLEAR_DISP_SCREEN;
            menu_flag = 0;
            user_password[2] = '1';
            attempt = '3';
            index = 0;



            //change password reinitialization
            index_conform = 0;
            index_new = 0;
            i_new = 0;
            i_conform = 0;

            option = 0;
            pointer = 0;
            choice = 0;

            clear_flag = 1;
        } else {
            clcd_print("CHANGE PASSWORD ", LINE1(0));
            clcd_print("UNSUCCESSFUL", LINE2(0));
            for (unsigned long int i = 0; i++ != 500000;);
            CLEAR_DISP_SCREEN;
            menu_flag = 0;
            user_password[2] = '1';
            attempt = '3';
            index = 0;
            //user_password[4] = "1111";


            //change password reinitialization
            index_conform = 0;
            index_new = 0;
            i_new = 0;
            i_conform = 0;

            option = 0;
            pointer = 0;
            choice = 0;

            clear_flag = 1;
        }

    }

    return;
}
