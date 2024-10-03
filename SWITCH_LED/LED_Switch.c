// program to toggle the LED based on swith
// if switch is pressed the LED is ON
// else LED is OFF
#include<lpc17xx.h>  
void delay(unsigned int a) ; 
int main() 
{ 
  int i,j; 
  LPC_GPIO1->FIODIR =(0XFF<<19); 
  LPC_GPIO2->FIODIR =~(1<<13);  
   
  while(1) 
  {   
   if(LPC_GPIO2->FIOPIN&(1<<13))// &(1<<13) to monitor the Switch
   { 
   LPC_GPIO1->FIOSET=(0xFF<<19); 
   delay(100);
   } 
   else
   { 
   LPC_GPIO1->FIOCLR=(0XFF<<19); 
   }   
  }  
}
void delay(unsigned int a) 
{ 
 unsigned int i,j; 
 for(i=0;i<a;i++) 
   for(j=0;j<5000;j++);   //5000*100/64 
} 