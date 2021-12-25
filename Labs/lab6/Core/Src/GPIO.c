/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */

#include "GPIO.h"


unsigned int PORT_ID;
unsigned int REG_ID;
//Generic fn.
#define GPIO_REG(PORT_ID , REG_ID)  ((unsigned int*)(PORT_ID + REG_ID))
//offset address for registers
#define MODER ((unsigned int)0x00)
#define OTYPER ((unsigned int)0x04)
#define OSPEEDR ((unsigned int)0x08)
#define PUPDR ((unsigned int)0x0c)
#define IDR ((unsigned int)0x10)
#define ODR ((unsigned int)0x14)
#define BSRR ((unsigned int)0x18)
#define LCKR ((unsigned int)0x1c)
#define AFRL ((unsigned int)0x20)
#define AFRH ((unsigned int)0x24)
//base address for ports
#define GPIOA ((unsigned int)0x40020000)
#define GPIOB ((unsigned int)0x40020400)
//RCC base address
#define RCC ((unsigned int)0x40023800)
//AHB1ENR
#define AHB1ENR ((unsigned int)0x30)








#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

unsigned int *lookuptable[2][10]={{GPIO_REG(GPIOA , MODER),GPIO_REG(GPIOA , OTYPER) ,GPIO_REG(GPIOA , OSPEEDR) , GPIO_REG(GPIOA , PUPDR) , GPIO_REG(GPIOA , IDR) , GPIO_REG(GPIOA , ODR) ,GPIO_REG(GPIOA , BSRR) , GPIO_REG(GPIOA , LCKR) ,GPIO_REG(GPIOA , AFRL) , GPIO_REG(GPIOA , AFRH)},
		                          {GPIO_REG(GPIOB , MODER),GPIO_REG(GPIOB , OTYPER) ,GPIO_REG(GPIOB , OSPEEDR) , GPIO_REG(GPIOB , PUPDR) , GPIO_REG(GPIOB , IDR) , GPIO_REG(GPIOB , ODR) ,GPIO_REG(GPIOB , BSRR) , GPIO_REG(GPIOB , LCKR) ,GPIO_REG(GPIOB , AFRL) , GPIO_REG(GPIOB , AFRH)}};


unsigned int *lookuotable2[1]={GPIO_REG(RCC , AHB1ENR)};

void GPIO_EnableClock(unsigned char PORT_ID) {

	*lookuotable2[0] |= (0x01 << PORT_ID);


}

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {

      *lookuptable[PORT_ID][0] &= ~(0x03 << 2 * PinNum);
      *lookuptable[PORT_ID][0] |= PinMode << 2 * PinNum;

      *lookuptable[PORT_ID][1] &= ~(1 << PinNum);
      *lookuptable[PORT_ID][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      *lookuptable[PORT_ID][3] &= ~(0x03 << 2 * PinNum);
      *lookuptable[PORT_ID][3] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;
      if (((*lookuptable[PORT_ID][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
        	*lookuptable[PORT_ID][5] |= (1 << PinNum);
        } else {
        	*lookuptable[PORT_ID][5] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }

  return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char read = 0;

      read = (*lookuptable[PORT_ID][4] & (1 << PinNum)) >> PinNum;

  return read;
}
