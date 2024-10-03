// based switch the LED toggle from increase and drecrease order
#include<lpc17xx.h>  
void delay(unsigned int a) 
{ 
    unsigned int i,j; 
 for(i=0;i<a;i++) 
   for(j=0;j<5000;j++);   //5000*50/64 
} 
int main() 
{ 
  int i,j; 
  LPC_GPIO1->FIODIR =(0XFF<<19); 
  LPC_GPIO2->FIODIR &=~(1<<12);  
  LPC_GPIO2->FIODIR &=~(1<<13);  
   
  while(1) 
  {   
     if(LPC_GPIO2->FIOPIN&(1<<13))
     { 
   for(i=19;i<=26;i++){ 
    LPC_GPIO1->FIOSET=(1<<i); 
    delay(50); 
   } 
   LPC_GPIO1->FIOCLR=(0XFF<<19); 
  } 
  else if(LPC_GPIO2->FIOPIN&(1<<12)){ 
   for(j=26;j>=19;j--){ 
    LPC_GPIO1->FIOSET=(1<<j); 
    delay(50); 
   } 
   LPC_GPIO1->FIOCLR=(0XFF<<19); 
 
  }  
     else{ 
   LPC_GPIO1->FIOCLR=(0XFF<<19); 
  }   
  }  
} 