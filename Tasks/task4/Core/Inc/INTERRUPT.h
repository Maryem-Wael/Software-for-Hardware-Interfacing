
#ifndef INTERRUPT_H
#define INTERRUPT_H
//Genric fn for interrupt
#define INTERRUPT_REG(PORT_ID , REG_ID)  ((unsigned int*)(PORT_ID + REG_ID))
//RCC
#define RCC_APB2ENR            INTERRUPT_REG(0x40023800 , 0X44)
//External interrupt registers
#define SYSCFG_EXTICR1         INTERRUPT_REG(0x40013800 , 0X08)
#define EXTI_IMR               INTERRUPT_REG(0x40013C00 , 0X00)
#define EXTI_RTSR              INTERRUPT_REG(0x40013C00 , 0X08)
#define EXTI_FTSR              INTERRUPT_REG(0x40013C00 , 0X0C)
#define EXTI_PR                INTERRUPT_REG(0x40013C00 , 0X14)
#define NVIC_ISER            INTERRUPT_REG(0xE000E100 , 0X00)
#define NVIC_ICER            INTERRUPT_REG(0xE000E100 , 0X180)

void SYSCFG_EnableClock();
void EXTI_CONFIG(unsigned char PinNum);

#endif
