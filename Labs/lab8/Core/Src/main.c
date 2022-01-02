#include "GPIO.h"


void USART_Init(){
	*RCC_APB1ENR |= 0x01<<17;

	*USART_CR1 |= 0x00<<15;
	*USART_CR1 |= 0x01<<13;
	*USART_CR1 |= 0x00<<12;
	*USART_CR1 |= 0x01<<3;

	*USART_BRR |= 0x683<<0;

	*USART_CR2 |= (0x00<<12);

}

void USART_Transmit(const char* str){

	while(*str != '\0'){
		while ((*USART_SR >> 6)&1){
			*USART_DR = *str;
			str++;
		}
	}
}


int main(void){

	GPIO_EnableClock(0);
	GPIO_Init(0,2,ALTERNATE_FUN,PUSH_PULL);
	*GPIOA_AFRL |= 0x07<<8;

	USART_Init();
	USART_Transmit("Hello World");

	while(1){

	}


}
