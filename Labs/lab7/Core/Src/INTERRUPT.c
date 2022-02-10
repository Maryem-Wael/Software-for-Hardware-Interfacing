#include "INTERRUPT.h"

void SYSCFG_EnableClock()
{
	*RCC_APB2ENR |= (0x01 << 14);
}

void EXTI_CONFIG(unsigned char PinNum)
{

    *SYSCFG_EXTICR1 &= ~(0x0F<<PinNum);
    *EXTI_FTSR |= 1 << PinNum;
    *EXTI_IMR |= 1 << PinNum;
    *NVIC_ISER = 1 << (6+PinNum);

}
