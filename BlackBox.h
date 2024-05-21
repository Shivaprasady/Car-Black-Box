/* 
 * File:   BlackBox.h
 * Author: shiva
 *
 * Created on 18 April, 2024, 8:36 AM
 */

#ifndef BLACKBOX_H
#define	BLACKBOX_H

#include"clcd.h"

unsigned long int delay11 = 0;
unsigned long int delay12 = 0;

#define SW1 0x0E
#define SW2 0x0D
#define SW3 0x0B
#define SW4 0x07
#define ALL_RELEASED 0x0F

unsigned char gear = 0;
char *ev[7] = {"ON", "GN", "GR", "G1", "G2", "G3", "G4"};

//adc
void init_adc();
unsigned short read_adc(unsigned char channel);
unsigned char temp;
unsigned short adc;
unsigned char sp[3];

//RTC
void init_i2c(void);
void i2c_start(void);
void i2c_rep_start(void);
void i2c_stop(void);
void i2c_write(unsigned char data);
unsigned char i2c_read(void);
                                   //ds1037
#define SLAVE_READ		0xD1
#define SLAVE_WRITE		0xD0


#define SEC_ADDR		0x00
#define MIN_ADDR		0x01
#define HOUR_ADDR		0x02
#define DAY_ADDR		0x03
#define DATE_ADDR		0x04
#define MONTH_ADDR		0x05
#define YEAR_ADDR		0x06
#define CNTL_ADDR		0x07

void init_ds1307(void);
void write_ds1307(unsigned char address1,  unsigned char data);
unsigned char read_ds1307(unsigned char address1);

unsigned char clock_reg[3];
unsigned char time[9];

                                    //time
static void get_time(void);
void display_time(void);
//Functions
void init_config();

//matrix
#define LEVEL 0
#define STATE_CHANGE 1

void init_matrix_keypad();

int main_flag = 0;

unsigned char read_switches(unsigned char detection);
unsigned char scan_key();

unsigned char once = 0;
unsigned char key;

void dashboard();
void password();

unsigned int wait = 0;
unsigned int wait1 = 0;
unsigned int count = 0;
unsigned int i = 0;
unsigned int sec = 120;
unsigned char seconds[4];

void init_timer();
void __interrupt() isr();


//menu function variables
char *menu[] = {"VIEW LOG", "SET TIME", "DOWNLOAD LOG", "CLEAR LOG", "CHANGE PASSWORD"};
int pointer = 0;
int choice = 0;
int menu_flag = -1;

//change password function variables
char new_password[5];
char conform_password[5];
int index_new = 0;
int index_conform = 0;
int i_new = 0;
int i_conform = 0;
unsigned char clear_flag = 1;

char original_password[5] = "0000";
char user_password[5];

void write_original_password(unsigned char*);

static int index = 0;
unsigned char attempt = '3';
int blocked = 0;

void main_menu();
unsigned int option = 0;

void view_menu();

void change_password();

//change time
void change_time(void);
char set_time[9];
char field_flag = 'h';
int set_time_once = 0; //case 1 for set time
int function_call_flag = 0;
unsigned int set_time_hour;
unsigned int set_time_minute;
unsigned int set_time_seconds;
void set_time_fun();

//EEPROM
#define EEPROM_WRITE 0xA0
#define EEPROM_READ 0xA1

void store_logs();

void write_24c02(unsigned char address, unsigned char data);
unsigned char read_24c02(unsigned char address);
char eeprom_address = 0x00;


//VIEW LOGS
void view_logs();

//CLEAR LOGS
void clear_logs();
unsigned char view_logs_flag = 0;
int no_of_EV = 0;

//UART
#define RX_PIN					TRISC7
#define TX_PIN					TRISC6

unsigned char ch;

void init_uart(void);
void putch(unsigned char byte);
int puts(const char *s);
unsigned char getch(void);
unsigned char getch_with_timeout(unsigned short max_time);
unsigned char getche(void);

void uart_display();

#endif	/* BLACKBOX_H */

