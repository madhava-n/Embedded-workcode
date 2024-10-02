#include<lpc17xx.h> 
void delay(unsigned int a); // declare delay funcion 
int main()
{
int i,j;
LPC_GPIO1->FIODIR =(0XFF<<19);
LPC_GPIO1->FIOCLR=(0xFF<<19);
while(1)
{
 for(i=19;i<=26;i++)  //led blink in increasing order
 { 
LPC_GPIO1->FIOSET=(1<<i);
delay(50);
LPC_GPIO1->FIOCLR=(1<<i);
}
for(j=26;j>=19;j--)  //led blink in decreasing order
{
LPC_GPIO1->FIOSET=(1<<j);
delay(50);
LPC_GPIO1->FIOCLR=(1<<j);
}
}
}
void delay(unsigned int a)// used for delay
{
 unsigned int i,j;
 for(i=0;i<a;i++)
 for(j=0;j<5000;j++); //5000*500/64
}

