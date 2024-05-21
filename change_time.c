/*
 * File:   change_time.c
 * Author: shiva
 *
 * Created on 7 May, 2024, 8:25 AM
 */


#include <xc.h>
#include"BlackBox.h"

/*char set_time[9];
char field_flag = 'h';
 */

int blink = 0;

void change_time(void) {

    if (key == 13) {
        set_time_fun();
        set_time_once = 0;
        menu_flag = 0;
        field_flag = 'h';
        CLEAR_DISP_SCREEN;
        return;
    }
    else if(key == 14)
    {
        menu_flag = 0;
        CLEAR_DISP_SCREEN;
        return;
    }

    if (set_time_once == 0) {
        for (int i = 0; i <= 9; i++) {
            set_time[i] = time[i];
        }
        set_time_hour = set_time[0] - '0';
        set_time_hour = (set_time_hour * 10) + (set_time[1] - '0');
        set_time_minute = set_time[3] - '0';
        set_time_minute = (set_time_minute * 10) + (set_time[4] - '0');
        set_time_seconds = set_time[6] - '0';
        set_time_seconds = (set_time_seconds * 10) + (set_time[7] - '0');
        set_time_once = 1;
    }

    if (wait1 < 10000) {
        blink = 0;
    } else {
        blink = 1;
    }
    
    if (field_flag == 'h') {
        if (key == 11) {
            field_flag = 'm';
            return;
        }
        if (key == 12) {
            if (set_time_hour < 23)
                set_time_hour++;
            else if (set_time_hour == 23)
                set_time_hour = 0;
            return;
        }
        if (blink == 0) {
            clcd_print(set_time, LINE2(0));
        } else {
            
            clcd_putch(' ', LINE2(0));
            clcd_putch(' ', LINE2(1));
        }
    } else if (field_flag == 'm') {
        if (key == 11) {
            field_flag = 's';
            return;
        }
        if (key == 12) {
            if (set_time_minute < 59)
                set_time_minute++;
            else if (set_time_minute == 59)
                set_time_minute = 0;
            return;
        }
        if (blink == 0) {
            clcd_print(set_time, LINE2(0));
        } else {
            
            clcd_putch(' ', LINE2(3));
            clcd_putch(' ', LINE2(4));
        }
    } else if (field_flag == 's') {
        if (key == 11) {
            field_flag = 'h';
            return;
        }
        if (key == 12) {
            if (set_time_seconds < 59)
                set_time_seconds++;
            else if (set_time_seconds == 59)
                set_time_seconds = 0;
            return;
        }
        if (blink == 0) {
            clcd_print(set_time, LINE2(0));
        } else {
            
            clcd_putch(' ', LINE2(6));
            clcd_putch(' ', LINE2(7));
        }
    }

    set_time[0] = (set_time_hour / 10) + '0';
    set_time[1] = (set_time_hour % 10) + '0';
    set_time[3] = (set_time_minute / 10) + '0';
    set_time[4] = (set_time_minute % 10) + '0';
    set_time[6] = (set_time_seconds / 10) + '0';
    set_time[7] = (set_time_seconds % 10) + '0';
    set_time[8] = '\0';

    clcd_print("HH:MM:SS", LINE1(0));
    



    return;
}

void set_time_fun() {
    if (key == 13) {
        unsigned char hour_rtc = ((set_time[0] - '0') << 4) | (set_time[1] - '0');
        unsigned char minute_rtc = ((set_time[3] - '0') << 4) | (set_time[4] - '0');
        unsigned char seconds_rtc = ((set_time[6] - '0') << 4) | (set_time[7] - '0');

        write_ds1307(0x02, hour_rtc);
        write_ds1307(0x01, minute_rtc);
        write_ds1307(0x00, seconds_rtc);

    }
}
