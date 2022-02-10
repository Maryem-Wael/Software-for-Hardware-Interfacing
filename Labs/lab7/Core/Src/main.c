
#include "GPIO.h"
#include "INTERRUPT.h"

void EXTI1_IRQHandler (void);

int main(void)
{ //Enable port A clock
  GPIO_EnableClock(0);
  SYSCFG_EnableClock();
  //configuration for pin 0(LED)
  GPIO_Init(0, 0,OUTPUT,PUSH_PULL);
  //configuration for pin 1(BUTTON)
  GPIO_Init(0, 1, INPUT, PULL_UP);
  GPIO_WritePin(0, 0, 1);
  EXTI_CONFIG(1);


  while (1)
  {
  }
  return 0;
}

void EXTI1_IRQHandler (void){
	unsigned char led;
	//reading the led and toggle
	led = 1^GPIO_ReadPin(0,0);
	//write on the led the toggled value
	GPIO_WritePin(0, 0, led);
	//clear flag
	*EXT1_PR |= 1;
}


