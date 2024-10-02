#include<lpc17xx.h> /
void delay(unsigned int a)
{
 unsigned int i,j;
for(i=0;i<a;i++)
for(j=0;j<5000;j++); //5000*500/64
}
int main()
{
int i,j;
LPC_GPIO1->FIODIR =(0XFF<<19); 
LPC_GPIO1->FIOCLR=(0xFF<<19);
while(1)
{
LPC_GPIO1->FIOSET=(0xFF<<19);
delay(100);
LPC_GPIO1->FIOCLR=(0xFF<<19);
 for(i=19,j=26;i<=26,j>=19;i++,j--)
 {
LPC_GPIO1->FIOSET=(1<<i);
LPC_GPIO1->FIOSET=(1<<j);
delay(100);
LPC_GPIO1->FIOCLR=(1<<i);
LPC_GPIO1->FIOCLR=(1<<j);
}
}
}


