/*
 * File:   menu.c
 * Author: shiva
 *
 * Created on 26 April, 2024, 7:41 AM
 */


#include <xc.h>
#include"BlackBox.h"

unsigned char download_index = 0;

void main_menu() {

    //CLEAR_DISP_SCREEN;
    if (menu_flag == 1) {
        view_menu();
        //CLEAR_DISP_SCREEN;
        return;
    } else {
        if (key == 11) {
            CLEAR_DISP_SCREEN;
            if (pointer == 1) {
                pointer--;
            } else if (option > 0) {
                option--;
            }
            if (choice > 0) {
                choice--;
            }
        } else if (key == 12) {
            CLEAR_DISP_SCREEN;
            if (pointer == 0) {
                pointer++;
            } else if (option < 3) {
                option++;
            }
            if (choice < 4) {
                choice++;
            }
        }
        if (pointer == 0) {
            clcd_print("*", LINE1(0));
        } else {
            clcd_print("*", LINE2(0));
        }
        clcd_print(menu[option], LINE1(1));
        clcd_print(menu[option + 1], LINE2(1));
    }


    if (key == 13) {
        CLEAR_DISP_SCREEN;
        set_time_once = 0;
        menu_flag = 1;
    }
    if (key == 14) {
        CLEAR_DISP_SCREEN;
        if (menu_flag == 1) {
            menu_flag = 0;
        } else {
            main_flag = 0;
        }


        //password reinitialization
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
        return;
    }

}

void view_menu() {
    switch (choice) {
        case 0:
            if (view_logs_flag == 0 && no_of_EV != 0) {
                view_logs();
            } else {
                clcd_print("NO LOGS", LINE1(0));
                __delay_ms(3000);
                menu_flag = 0;
                CLEAR_DISP_SCREEN;
            }

            break;
        case 1:

            change_time();

            break;
        case 2:
            if (view_logs_flag == 0) {
                uart_display();
                menu_flag = 0;
                index = 0;
            }

            //while (1);

            break;
        case 3:
            clear_logs();

            //while (1);
            break;
        case 4:

            change_password();

            break;
    }
}
