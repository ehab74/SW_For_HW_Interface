#include "stm32f401cc_interface.h"
#include "GPIO.h"

void delay(int sec){
	for (int i = 0;i<sec;i++){
		  }
}


int main(void){

	GPIO_Init('B', 3 , INPUT, PULL_UP);
	GPIO_Init('B', 5 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 6 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 7 , OUTPUT, PUSH_PULL);

    int sec = 1000000;
    int cnt = 0;
	while(1){
		if (!GPIO_ReadPin('B',3)){
			delay(sec/100);
			if (!GPIO_ReadPin('B',3))
			{
				cnt = (cnt+1)%8;
				GPIO_WritePin('B',5,0x01&cnt);
				GPIO_WritePin('B',6,0x01&(cnt>>1));
				GPIO_WritePin('B',7,0x01&(cnt>>2));

			}
		}
		delay(sec);
	}
	return 0;

}
