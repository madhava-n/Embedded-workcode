//timer program
#include<lpc17xx.h>
void led_toggle(unsigned int a);
void delay(unsigned int b);
int main()
{
 LPC_GPIO1->FIODIR=(0xFF<<19);//config led as output
 //basic config
 LPC_SC->PCONP|=(1<<2);
 LPC_SC->PCLKSEL0|=(1<<2);
 LPC_TIM0->PR=3;

 LPC_TIM0->MR0=5000000;
 LPC_TIM0->MR1=7000000;
 LPC_TIM0->MR2=9000000;
 LPC_TIM0->MR3=11000000;

 LPC_TIM0->MCR=(1<<10)|(1<<9)|(1<<6)|(1<<3)|(1<<0);

 //whenever app is started it should start with 0->TCR
 //
 LPC_TIM0->TCR=(1<<1);
 LPC_TIM0->TCR=(1<<0);
 

 while(1)
 {
  //check the 
  //whenever MR0=0bit
  //MR1=1Bit
  //MR2=2bit
  //MR3=3bit
   if(LPC_TIM0->IR&(1<<0))//MR0
   {
   led_toggle(19);
   LPC_TIM0->IR=(1<<0);
   }			   												
   if(LPC_TIM0->IR&(1<<1))//MR1
   {
   led_toggle(20);
   LPC_TIM0->IR=(1<<1);
   }
   if(LPC_TIM0->IR&(1<<2))//MR2
   {
   led_toggle(21);
   LPC_TIM0->IR=(1<<2);
   }
   if(LPC_TIM0->IR&(1<<3))//MR3
   {
   led_toggle(22);
   LPC_TIM0->IR=(1<<3);
   }
  }
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