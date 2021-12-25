/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
//Genric fn for interrupt
#define INTERRUPT_REG(PORT_ID , REG_ID)  ((unsigned int*)(PORT_ID + REG_ID))
//RCC
#define RCC_APB2ENR            INTERRUPT_REG(0x40023800 , 0X44)
//External interrupt registers
#define SYSCFG_EXTICR1         INTERRUPT_REG(0x40013800 , 0X08)
#define EXTI_IMR               INTERRUPT_REG(0x40013C00 , 0X00)
#define EXTI_RTSR              INTERRUPT_REG(0x40013C00 , 0X08)
#define EXTI_FTSR              INTERRUPT_REG(0x40013C00 , 0X0C)
#define EXT1_PR                INTERRUPT_REG(0x40013C00 , 0X14)
#define NVIC_ISER              INTERRUPT_REG(0xE000E100 , 0X00)

void EXTI1_IRQHandler (void);

int main(void)
{ //Enable port A clock
  GPIO_EnableClock(0);
  //configuration for pin 0(Led)
  GPIO_Init(0, 0,OUTPUT,PUSH_PULL);
  //configuration for pin 1(button)
  GPIO_Init(0, 1, INPUT, PULL_UP);
  GPIO_WritePin(0, 0, 0);
  //clock for SYSCFG register
  *RCC_APB2ENR  |= (1<<14);
  //External interrupt
  *SYSCFG_EXTICR1 &= ~(0x0F<<4);
  //unmask
  *EXTI_IMR |= (1<<1);
  //external interrupt to failing edge
  *EXTI_FTSR |= (1<<1);
  //disable external interrupt for raising edge
  *EXTI_RTSR &= ~(1<<1);
  //Enable external interrupt 1
  *NVIC_ISER |= (1<<7);



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
	*EXTI_RTSR |= 1;
}


