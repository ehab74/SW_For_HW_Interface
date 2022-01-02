/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void delay30ms() {
  unsigned int i;
  for (i = 0; i < 30000; i++) {
  }
}

void keypadCallouts_KeyPressNotification(){
	char key = keypad_GetKey();
	if (key!=-1){
		if (key=='#' || key== '*')
			key = 0;
		for (int i = 0; i < 7; i++) {
		            GPIO_WritePin('A', i, (sevenSegHex[key] & (1 << i)) >> i);
		          }
	}
}

int main(void) {

  GPIO_EnableClock('A');
  for (int i = 0; i < 7; i++) {
    GPIO_Init('A', i, OUTPUT, PUSH_PULL);
  } 

  keypad_init();

  while (1) {
	keypad_manage();
	delay30ms();
  }
  return 0;
}
