#include"lcd_header.h"						 
void lcd_config(void)
{
  LPC_GPIO0->FIODIR|=RS|EN|DATA;
  lcd_cmd(0x30);
  lcd_cmd(0x01);
  lcd_cmd(0x0E);
  lcd_cmd(0x80);
}
void lcd_cmd(unsigned char c)
{
																								  
 LPC_GPIO0->FIOCLR=(0xFF<<15); 
 LPC_GPIO0->FIOSET=(c<<15);
 LPC_GPIO0->FIOCLR=RS;
 LPC_GPIO0->FIOSET=EN;
 delay(10);
 LPC_GPIO0->FIOCLR=EN;
}
void lcd_data(unsigned char d)
{
 LPC_GPIO0->FIOCLR=(0xFF<<15);
 LPC_GPIO0->FIOSET=(d<<15);
 LPC_GPIO0->FIOSET=RS;
 LPC_GPIO0->FIOSET=EN;
 delay(50);
 LPC_GPIO0->FIOCLR=EN;
}
void lcd_str(unsigned char *ptr)
{
 while(*ptr!='\0'){
 lcd_data(*ptr);
 *ptr++;
 }
 }

void lcd_num(unsigned long long int n)
{
 if(n)
 {
  lcd_num(n/10);
  lcd_data(n%10+0x30);
 }
}
void delay(unsigned int a)
{
 unsigned int i,j;
 for(i=0;i<a;i++)
  for(j=0;j<5000;j++);
}
