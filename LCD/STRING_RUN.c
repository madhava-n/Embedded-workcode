#include<lpc17xx.h>
#include "LCD_FUNCTION.c" 
int main() 
{ 
lcd_config(); 
lcd_data("Madhavan"); 
while(1){ 
lcd_cmd(0x18);}   // this will left shift the data continuously  
}