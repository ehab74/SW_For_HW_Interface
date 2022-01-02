#include "stm32f401cc_interface.h"

void delay(int sec){
	for (int i = 0;i<sec;i++){
		  }
}

int main(void) {

  RCC_AHB1ENR |=1<<0;
  GPIOA_MODER |=1<<0;
  GPIOA_OTYPER &= ~(1<<0);

  while (1) {
	  int sec = 1000000;
	  GPIOA_ODR |= 1<<0;
	  delay(sec);
	  GPIOA_ODR &= ~(1<<0);
	  delay(sec);
  }
  return 0;
}
