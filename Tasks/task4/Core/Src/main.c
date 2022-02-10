
#include "GPIO.h"
#include "INTERRUPT.h"


void EXTI0_IRQHandler ();
void EXTI1_IRQHandler ();
void SevenSeg();
//lookup for seven segments
static unsigned char seven_Seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char counter=0 ;
int main(void)
{ //Enable port B clock
  GPIO_EnableClock(0);
  //configuration for pin 0(button1)
  GPIO_Init(0, 0,INPUT,PULL_UP);
  //configuration for pin 1(button2)
  GPIO_Init(0, 1, INPUT, PULL_UP);
  //clock for SYSCFG register
  SYSCFG_EnableClock();
  //EXTI
    EXTI_CONFIG(0);
    EXTI_CONFIG(1);
  SevenSeg();
  unsigned char value_counter;

  while (1)
  {
	  *NVIC_ICER |= (1<<7);
	  *NVIC_ICER |= (1<<6);

	  value_counter=counter;

	  *NVIC_ISER |= (1<<6);
	  *NVIC_ISER |= (1<<7);

	  for (unsigned char i = 0; i < 7; i++){
		  	  GPIO_WritePin(1, i, (seven_Seg[value_counter] & (1 << i)) >> i);
	  	  }

  }
  return 0;
}

void EXTI0_IRQHandler (void){

	*NVIC_ICER |= (1<<7);
//increment the counter
	counter++;
//set the counter=zero if it's greater than 9
	if(counter>9){
		counter=0;
	}
//enable external interrupt
	*NVIC_ISER |= (1<<7);
//clear the flag
	*EXTI_PR|= (1<<0);
}


void EXTI1_IRQHandler (void){
//disable external interrupt
	*NVIC_ICER |= (1<<6);
///decrement the counter and setting it=9 if it's=equal 0
	if(0==counter){
			counter=9;
		}
	else {
		counter--;
	}
//enable external interrupt
	*NVIC_ISER |= (1<<6);
//clear the flag
	*EXTI_PR |= (1<<1);

}
void SevenSeg(){
	  unsigned char i=0;
	  GPIO_EnableClock(1);
	  for (; i < 7; i++) {
		  GPIO_Init(1, i, OUTPUT, PUSH_PULL);
	  }
}
