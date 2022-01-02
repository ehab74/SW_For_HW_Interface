#include "GPIO.h"

unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int counter = 0;

void display(int localCounter){
	for (int i = 0; i < 7; i++) {
	  GPIO_WritePin(1, i, (sevenSegHex[localCounter] & (1 << i)) >> i);
	}
}

void increment(void){
	counter = (counter+1)%10;

	*EXTI_PR |= (0x01<<0);
}

void decrement(void){
	counter--;
	if (counter<0)
		counter = 9;

	*EXTI_PR |= (0x01<<1);
}


int main(void){

	GPIO_EnableClock(0);
	GPIO_EnableClock(1);
	*RCC_APB2ENR |= (0x01<<14);

	GPIO_Init(0,0,INPUT,PULL_UP);
	GPIO_Init(0,1,INPUT,PULL_UP);

	for (int i = 0;i<7;i++)
	  GPIO_Init(1,i,OUTPUT,PUSH_PULL);

	*SYSCFG_EXTICR &= ~(0xff<<0);
	*EXTI_IMR |= 0x03<<0;
	*EXTI_FTSR |= 0x03<<0;

	*NVIC_ISER = 0x03<<6;

	int localCounter;

	while(1){
		*NVIC_ICER = 0x03<<6;
		localCounter = counter;
		*NVIC_ISER = 0x03<<6;
		display(localCounter);
	}

}
