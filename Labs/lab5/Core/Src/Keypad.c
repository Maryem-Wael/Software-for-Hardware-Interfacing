
#include "GPIO.h"
#include "Keypad.h"
#include "stm32f401cc_interface.h"

unsigned char KeyPad_Array[3][4] = {{1,4,7,'*'},{2,5,8,0},{3, 6,9,'#'}};
unsigned char KeyPad_State = Released;
unsigned char Key_Value = 0;

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
	KeyPad_State = Released;
	return Key_Value;

}

void KeyPad_Manage()
{

	if(KeyPad_State == Released)
	{
		for(int i=0; i < 3; i++)
		{
			GPIO_WritePin('B', i, 0);
			for(int j=3; j < 7; j++)
			{
				if (GPIO_ReadPin('B', j) == 0)
				{delay(10000);
					if (GPIO_ReadPin('B', j) == 0){
						Key_Value = KeyPad_Array[i][j-3];
					    KeyPad_State = Pressed;
					    KeyPad_CallOut_Button_Pressed_Notification();}
				}
			 }
			GPIO_WritePin('B', i, 1);
		 }
	 }

}
void delay(int milli_secs)
{
    for (unsigned int i = 0; i < milli_secs; i++)
    {
    }
}
