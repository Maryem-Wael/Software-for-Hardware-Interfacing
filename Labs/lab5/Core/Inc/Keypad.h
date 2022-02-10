

#ifndef KEYPAD_H
#define KEYPAD_H

#include "stm32f401xc.h"

#define Released ((unsigned char)1)
#define Pressed ((unsigned char)0)

void KeyPad_Init();
void KeyPad_Manage();
unsigned char KeyPad_GetKey();
void delay(int secs);
void KeyPad_CallOut_Button_Pressed_Notification();
void Display_Key(unsigned char key);



#endif /* KEYPAD_H */
