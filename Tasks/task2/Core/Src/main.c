#include "stm32f401cc_interface.h"



int state;
int i;
void delay(int sec)
{
    for (i=0;i<=sec;i++){}
}
int color=1;
int main()
{

    RCC_AHB1ENR |= (1<<1);
    GPIOB_MODER &= ~(1<<(2*3));
    GPIOB_MODER &= ~(1<<(2*5));
    GPIOB_MODER &= ~(1<<(2*6));
    GPIOB_MODER &= ~(1<<(2*7));
    GPIOB_MODER |= (1<<(2*5));
	GPIOB_MODER |= (1<<(2*6));
	GPIOB_MODER |= (1<<(2*7));
	GPIOB_OTYPER &= ~(7<<5);
	while(1){
        int state= ((GPIOB_IDR & (1<<3))>>3);
        delay(1000);

        if(state&&!((GPIOB_IDR & (1<<3))>>3))
            {GPIOB_ODR &= ~(7<<5);
        	GPIOB_ODR |= (color<<5);
        	color+=1;
        	if (color>=7)
        		{color=1;}}


	}


    return 0;
}
