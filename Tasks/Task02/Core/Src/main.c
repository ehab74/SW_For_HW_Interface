#include "stm32f401cc_interface.h"

void delay(int sec){
	for (int i = 0;i<sec;i++){
		  }
}

int main(void) {

  RCC_AHB1ENR |=1<<1;
  GPIOB_MODER |=42<<9;
  GPIOB_OTYPER &= ~(7<<5);
  GPIOB_PUPDR |= 1<<6;
  int sec = 1000000;
  int cnt = 0;
  while (1) {
	  if (GPIOB_IDR & (1<<3)){
		  delay(sec/1000);
		  if (GPIOB_IDR & (1<<3)){
			  cnt = (cnt +1)%8;
			  GPIOB_ODR &= 0;
			  delay(sec/100);
		  }
	  }
	  GPIOB_ODR |= cnt<<5;
	  delay(sec);
  }
  return 0;
}
