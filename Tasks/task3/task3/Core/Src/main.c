#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

void delay(int sec){
	for (int i=0 ; i<sec ; i++){}
}
int main(void) {
	unsigned int color=0 ;
	unsigned int button=0 ;
	//button
	GPIO_Init('B', 3 , INPUT, PUSH_PULL);
	//RGB
	GPIO_Init('B', 5 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 6 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 7 , OUTPUT, PUSH_PULL);

  while (1) {

	  button = GPIO_ReadPin('B' , 3 );
	  delay(10000);
	  button=GPIO_ReadPin('B' , 3 );
	  if(button == 0){
		  color++;
		  //next color of RGB
		  GPIO_WritePin('B',5,((1<<5)&(color<<5)));
		  GPIO_WritePin('B',6,((1<<6)&(color<<5)));
		  GPIO_WritePin('B',7,((1<<7)&(color<<5)));
	  }
	 while(button == 0){
		  button=GPIO_ReadPin('B' ,3 );
	 }


  }


  return 0;
}
