#include<lpc17xx.h>
#include"LCD_FUNCTION.c"
int main()
{
lcd_config(); 
lcdstr("Madhavan"); 
lcd_cmd(0xc0);
 
lcd_num(9876543210);
}
