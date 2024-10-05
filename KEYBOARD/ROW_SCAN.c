//this program to find which row key is pressed in keyboard in row wise
#include<lpc17xx.h>
#include"LCD_FUNCTION.c" // this is used to configure the LCD and this program has placed in LCD file
#define ROWS (0x0F<<4);
#define COLS (0x0F<<0);
void rows_scan(void);
int main()
{
lcd_config();// for configure lcd
while(1)
{
rows_scan();// call row_scan infinite time
}
}
void rows_scan(void)
{
 unsigned int val;
 LPC_GPIO2->FIODIR|=COLS;
 LPC_GPIO2->FIODIR&=~ROWS;
 val=LPC_GPIO2->FIOPIN&ROWS;

 val=val>>4;
 switch(val)
 {
  case 0x0E:lcd_str("ROW 1 is pressed");
  delay(100);
  break;

  case 0x0D:lcd_str("Row 2 is pressed");
  delay(100);
  break;

  case 0x0B:lcd_str("Row 3 is pressed");
  delay(100);
  break;
  
  case 0x07:lcd_str("Row 4 is pressed");
  delay(100);
  break;
  
  default:lcd_cmd(0x01);
  delay(100);
  
}
} 