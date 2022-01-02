#include "GPIO.h"

unsigned char button_pressed = 0;
unsigned char keys[4][3] = {{1,2,3},
            {4,5,6},
            {7,8,9},
            {'*', 0, '#'}};
unsigned char key = -1;

void keypad_init(){
	GPIO_EnableClock(1);

	for (int i=0;i<3;i++)
	 GPIO_Init(1,i, OUTPUT,PUSH_PULL);

	for (int i=3;i<7;i++)
	 GPIO_Init(1,i,INPUT,PULL_UP);
}

void keypad_manage(){
	if (!button_pressed){
	 for (int i = 0;i<3;i++){
		GPIO_WritePin(1,i,0);
		GPIO_WritePin(1,(i+1)%3,1);
		GPIO_WritePin(1,(i+2)%3,1);
		for (int j = 0;j<4;j++)
		{
			unsigned char row = GPIO_ReadPin(1,j+3);
			if (!row){
				button_pressed = 1;
				key = keys[j][i];
				keypadCallouts_KeyPressNotification();
			}
		}
	}
 }
}

char keypad_GetKey(){
	if (button_pressed){
		button_pressed = 0;
		return key;
	}
	return -1;
}
