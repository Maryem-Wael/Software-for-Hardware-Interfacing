#include "USART.h"
#include "GPIO.h"


void USART_EnableClock(void) {
	*RCC_APB1ENR  |= (1 << 17);

}

void USART_INIT(void)

{
	*GPIOA_AFRL   |= (0x07 << 8) ;
	*USART_CR1    |= (1 << 13);
	*USART_CR1    |= (1 << 3);
	*USART_CR1    &= ~(1 << 15);
    *USART_CR1    &= ~(1 << 12);
  	*USART_CR2    &= ~(0x3 << 12);
	*USART_BRR     = 0x683;
}


void USART_TRANSMIT(char *string){
	unsigned char i;
	for(i=0;string[i] != '\0';i++){
		*USART_DR = string[i];
		while(TRANS_COMPLETE==0){
			}
	}
}
