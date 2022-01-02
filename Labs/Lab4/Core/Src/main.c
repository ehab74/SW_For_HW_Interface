#include "stm32f401cc_interface.h"
#include "GPIO.h"

void delay(int sec){
	for (int i = 0;i<sec;i++){
		  }
}


int main(void){

//	GPIO_Init('B', 3 , INPUT, PULL_UP);
	for (int i =0;i<7;i++)
	GPIO_Init('A', i , OUTPUT, PUSH_PULL);


    int sec = 1000000;
    int cnt = 0;
	while(1){
		switch(cnt){
		 case(0):
			 GPIO_WritePin('A',6,0x01);
		 break;
		 case(1):
		     GPIO_WritePin('A',0,0x01);
		     for(int i =3;i<7;i++){
		      GPIO_WritePin('A',i,0x01);
		     }
		 break;
		 case(2):
    	    GPIO_WritePin('A',2,0x01);
		    GPIO_WritePin('A',5,0x01);
		    break;
		 case(3):
    	    GPIO_WritePin('A',4,0x01);
		    GPIO_WritePin('A',5,0x01);
		    break;
		 case(4):
    	    GPIO_WritePin('A',0,0x01);
		    GPIO_WritePin('A',3,0x01);
		    GPIO_WritePin('A',4,0x01);
		    break;
		 case(5):
    	    GPIO_WritePin('A',1,0x01);
		    GPIO_WritePin('A',4,0x01);
		    break;
		 case(6):
    	    GPIO_WritePin('A',1,0x01);
		    break;
		 case(7):
		  for(int i =3;i<7;i++){
		      GPIO_WritePin('A',i,0x01);
		    }
		    break;
		 case(8):
		    break;
		 case(9):
    	    GPIO_WritePin('A',4,0x01);

		    break;
		}
		delay(sec);
		for (int i = 0;i<7;i++){
						GPIO_WritePin('A',i,0);
				}
		cnt = (cnt+1)%10;
	}
	return 0;

}
