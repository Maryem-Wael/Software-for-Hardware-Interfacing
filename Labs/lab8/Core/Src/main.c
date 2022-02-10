
#include "GPIO.h"
#include "USART.h"


int main(void)
{   // Enable GPIOA
    GPIO_EnableClock(0);
    //Terminal
    GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);
    //Enable USART clock
    USART_EnableClock();
    USART_INIT();
    USART_TRANSMIT("Hello World!");
    while (1){}
    return 0;
}

