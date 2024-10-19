// THIS PROGRAM FOR POTENTIAL VALUE READING
#include<lpc17xx.h>
#include"lcd_fuc.c"// THIS FOR CALL LCD FILE FOR LCD CONFIGURE
int main()
{
int adc_val;
 lcd_config();
 LPC_SC->PCONP|=(1<<12);//enable the power config
 LPC_SC->PCLKSEL0|=(1<<25)|(1<<24);//enable clk signal
 LPC_PINCON->PINSEL1|=(1<<18); //config the AD2

 //ADC config
 //PIN->Select the channel adc is 2(1<<2)
 //CLK DIU-->8 is start .8421(4<<8)
 //burst mode--->16(1<<16)
 //power down --->21(1<<21)
 LPC_ADC->ADCR|=(1<<2)|(4<<8)|(1<<16)|(1<<21);
 //to get  temp value --->DIGITAL
 //END ON CONVERSION  ------>global data register.
 while(1)
 {
  while(!(LPC_ADC->ADGDR&(1<<31)))
  {
   val=LPC_ADC->ADDR2&(0xFFF<<4);
   val=(val>>4);
   val=(val/13.6);
   lcd_datai(val);
   delay(100);
   lcd_cmd(0x01);
   delay(100);
   }
 }
}