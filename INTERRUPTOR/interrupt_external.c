//generate an external interpt in exit from switch p2.12
//toggle p0.21-p0.24 in the ISR
//toggle
#include<lpc17xx.h>
void led_toggle(unsigned int a);
void delay(unsigned int b);
void External_Int_Config(void);
int main()
{
 LPC_GPIO1->FIODIR|=(0xFF<<19);

 while(1)
 {
  led_toggle(19);
  External_Int_Config();
 }
}
void led_   toggle(unsigned int a)
 {
  LPC_GPIO1->FIOSET=(1<<a);
  delay(100);
  LPC_GPIO1->FIOCLR=(1<<a);
  delay(100);
 }
void delay(unsigned int b)
{
 unsigned int i,j;
 for(i=0;i<b;i++)
  for(j=0;j<5000;j++);
}
void External_Int_Config(void)
{
 LPC_PINCON->PINSEL4|=(1<<24);
 LPC_SC->EXTMODE&=~(1<<2);
 LPC_SC->EXTPOLAR=(1<<2);

 NVIC_EnableIRQ(EINT2_IRQn);
}
void EINT2_IRQHandler(void)
{
 LPC_GPIO1->FIOSET|=(0xF<<21);
 delay(100);
 LPC_GPIO1->FIOCLR|=(0xF<<21);
 delay(100);
 LPC_SC->EXTINT|=(1<<2);
}
	