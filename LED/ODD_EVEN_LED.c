#include<lpc17xx.h>
void delay (unsigned int a);
int main()
 {
   LPC_GPIO1->FIODIR=(0xFF<<19);
 while(1)
 {
  LPC_GPIO1->FIOCLR=(0X55<<19); 
  LPC_GPIO1->FIOSET=(0XAA<<19); // even leds to ON (0xAA)
  delay(500);
  LPC_GPIO1->FIOCLR=(0XAA<<19);
  LPC_GPIO1->FIOSET=(0X55<<19);// odd leds to ON
  delay(500);
 }
}
void delay (unsigned int a)
{
 unsigned int i,j;
 for (i=0;i<a;i++)
   for(j=0;j<5000;j++);
}