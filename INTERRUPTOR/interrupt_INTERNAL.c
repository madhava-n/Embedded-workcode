//program to generate an interrupt from timer0 and togle p1.26 for every 5sec in ISR
//LED p1.16 in main program

#include<lpc17xx.h>
void timer_config(void);
void led_toggle(unsigned int a);
void delay(unsigned int b);
int main()
{
 timer_config();
 // config the LED
 LPC_GPIO1->FIODIR|=(0xFF<<19);
 NVIC_EnableIRQ(TIMER0_IRQn);
 while(1)
 {
 led_toggle(19);
 }
}
void timer_config(void
)
{
 LPC_SC->PCONP|=(1<<1);
 LPC_SC->PCLKSEL0|=(1<<2);
 LPC_TIM0->PR=3;
 LPC_TIM0->MR0=5000000;
 LPC_TIM0->MCR|=(1<<1)|(1<<0);
 LPC_TIM0->TCR=(1<<1);
 LPC_TIM0->TCR=(1<<0);
}
void TIMER0_IRQHandler(void)
{
 led_toggle(26);
 LPC_TIM0->IR=(1<<0);
}
void led_toggle(unsigned int a)
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


