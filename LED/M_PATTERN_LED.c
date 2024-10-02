#include<lpc17xx.h>
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
while(1)
{
LPC_GPIO1->FIOSET=(1<<19);
LPC_GPIO1->FIOSET=(1<<26);
 for(i=20,j=25;i<=22,j>=23;i++,j--){
LPC_GPIO1->FIOSET=(1<<i);
LPC_GPIO1->FIOSET=(1<<j);
delay(50);
LPC_GPIO1->FIOCLR=(1<<i);
LPC_GPIO1->FIOCLR=(1<<j);
}
}
}