/*
 * File:   view_logs.c
 * Author: shiva
 *
 * Created on 9 May, 2024, 8:54 AM
 */


#include <xc.h>
#include"BlackBox.h"
unsigned char index_viewLogs = 0;
unsigned char read_Address = 0x00;

void view_logs() {
    
    if(key == 14)
    {
        CLEAR_DISP_SCREEN;
        menu_flag = 0;
        return;
    }
    
    clcd_print("# TIME     EV SP", LINE1(0));
    
    if(key == 11 && index_viewLogs > 0 && no_of_EV > 0)
        index_viewLogs--;
    else if(key == 12 && index_viewLogs < 9 && no_of_EV-1 > index_viewLogs)
        index_viewLogs++;
    
    clcd_putch(index_viewLogs + '0',LINE2(0));
    clcd_putch(read_24c02(((index_viewLogs*10)+0)),LINE2(2));
    clcd_putch(read_24c02(((index_viewLogs*10)+1)),LINE2(3));
    clcd_putch(':',LINE2(4));
    clcd_putch(read_24c02(((index_viewLogs*10)+2)),LINE2(5));
    clcd_putch(read_24c02(((index_viewLogs*10)+3)),LINE2(6));
    clcd_putch(':',LINE2(7));
    clcd_putch(read_24c02(((index_viewLogs*10)+4)),LINE2(8));
    clcd_putch(read_24c02(((index_viewLogs*10)+5)),LINE2(9));
    clcd_putch(' ',LINE2(10));
    clcd_putch(read_24c02(((index_viewLogs*10)+6)),LINE2(11));
    clcd_putch(read_24c02(((index_viewLogs*10)+7)),LINE2(12));
    clcd_putch(' ',LINE2(13));
    clcd_putch(read_24c02(((index_viewLogs*10)+8)),LINE2(14));
    clcd_putch(read_24c02(((index_viewLogs*10)+9)),LINE2(15));
    
    return;
}
