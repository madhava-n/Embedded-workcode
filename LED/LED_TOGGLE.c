#include<lpc17xx.h> //it is common for the arm proccessor FIO- fast
void delay(unsigned int a)
{
 unsigned int i,j;
for(i=0;i<a;i++)
for(j=0;j<5000;j++); //5000*500/64
}
int main()
{
LPC_GPIO1->FIODIR =(1<<19); //direct 19 pin leds
while(1)
{
LPC_GPIO1->FIOSET=(1<<19);// ON 19 pin led
delay(500);
LPC_GPIO1->FIOCLR=(1<<19);// off 19 pin led
delay(500);
}
}
