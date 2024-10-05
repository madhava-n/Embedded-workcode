// this program to find the which key is pressed in keyboard
#include<lpc17xx.h>
#include "LCD_FUNCTION.c"

#define ROWS (0x0F<<4)
#define COLS (0X0F<<0)


void keypad(void){
	int val1,val2;
	LPC_GPIO2->FIODIR|=COLS;
	LPC_GPIO2->FIODIR&=~ROWS;

 	val1=LPC_GPIO2->FIOPIN&ROWS;
	val1=val1>>4;

	LPC_GPIO2->FIODIR|=ROWS;
	LPC_GPIO2->FIODIR&=~COLS;


 	val2=LPC_GPIO2->FIOPIN&COLS;
	val2=val2>>0;
	if(val1==0X0E && val2==0X0E){
		lcd_str("s-0");
		delay(10);	
	}
	else if(val1==0X0E && val2==0X0D){
		lcd_str("s-1");
		delay(10);
	}
	else if(val1==0X0E && val2==0X0B){
		lcd_str("s-2");
		delay(10);
	}
	else if(val1==0X0E && val2==0X07){
		lcd_str("s-3");
		delay(10);
	}
	else if(val1==0X0D && val2==0X0E){
		lcd_str("s-4");
		delay(10);
	}
	else if(val1==0X0D && val2==0X0D){
		lcd_str("s-5");
		delay(10);
	}
	else if(val1==0X0D && val2==0X0B){
		lcd_str("s-6");
		delay(10);
	}
	else if(val1==0X0D && val2==0X07){
		lcd_str("s-7");
		delay(10);
	}
	else if(val1==0X0B && val2==0X0E){
		lcd_str("s-8");
		delay(10);
	}
	else if(val1==0X0B && val2==0X0D){
		lcd_str("s-9");
		delay(10);
	}
	else if(val1==0X0B && val2==0X0B){
		lcd_str("s-A");
		delay(10);
	}
	else if(val1==0X0B && val2==0X07){
		lcd_str("s-B");
		delay(10);
	}
	else if(val1==0X07 && val2==0X0E){
		lcd_str("s-C");
		delay(10);
	}
	else if(val1==0X07 && val2==0X0D){
		lcd_str("s-D");
		delay(10);
	}
	else if(val1==0X07 && val2==0X0B){
		lcd_str("s-E");
		delay(10);
	}
	else if(val1==0X07 && val2==0X07){
		lcd_str("s-F");
		delay(10);
	}
	else{
		lcd_cmd(0x01);
		delay(10);
	}

}
int main(){
	lcd_config();// this is used to configure the lcd
	while(1){
		keypad();
	}	
} 