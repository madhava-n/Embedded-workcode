#include<lpc17xx.h>
#define RS (1<<10)
#define Rw (1<<12)
#define EN (1<<11)
#define DATA (0xFF<<15)
void lcd_datai(unsigned long long int n);
void delay(unsigned int a);
void lcd_data(unsigned char d);
void lcd_cmd(unsigned char c);
void lcd_config(void);
								   