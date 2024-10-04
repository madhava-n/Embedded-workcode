#include<lpc17xx.h>
#include"LCD_FUNCTION.c"
int main()
{
int i;
  char a[8]="MADHAVAN";
  lcd_config();
  while(1)
  {  
  for(i=0;i<8;i++)
  {
  lcd_data(a[i]);
  delay(50);
  }
  delay(100); 
  lcd_cmd(0x01);

  }
}