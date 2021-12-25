/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"
#include "stm32f401cc_interface.h"

unsigned char KeyPadButton = Released;
unsigned char Key_Pressed = 0;
unsigned char KeyPad_array[3][4] = {{1,
		                            4,
									7,
									'*'},
		                           {2,
		                            5,
									8,
									0},

									{3,
									 6,
									 9,
									 '#'}};

void KeyPad_Init()
{
	 GPIO_EnableClock('B');

	  for (int i = 0; i < 3; i++)
	  {
	      GPIO_Init('B', i, OUTPUT, PUSH_PULL);
	  }
	  for (int i = 3; i < 7; i++)
	  {
		  GPIO_Init('B', i, INPUT, PULL_UP);
	  }
}

unsigned char KeyPad_GetKey()
{
	if(KeyPadButton == Pressed)
	{
		KeyPadButton = Released;
	    return Key_Pressed;
	}
	else
	{
		return 0;
	}
}

void KeyPad_Manage()
{
	if(KeyPadButton == Pressed)
	{
		KeyPad_CallOut_Button_Pressed_Notification();
	}

	if(KeyPadButton == Released)
	{
		for(int i=0; i < 3; i++)
		{
			GPIO_WritePin('B', i, 0);
			for(int j=0; j < 4; j++)
			{
				if (GPIO_ReadPin('B', (j+3)) == 0 && !(i == 0 && j == 3) && !(i == 2 && j == 3) && KeyPadButton == Released)
				{
					Key_Pressed = KeyPad_array[i][j];
					KeyPadButton = Pressed;
					KeyPad_CallOut_Button_Pressed_Notification();
				}
			 }
			GPIO_WritePin('B', i, 1);
		 }
	 }

}
