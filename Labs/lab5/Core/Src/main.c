
#include "GPIO.h"
#include "Keypad.h"

unsigned char sevenSegTable[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char key = 0;



int main(void)
{
  GPIO_EnableClock('A');
  for (int i = 0; i < 7; i++)
	  {GPIO_Init('A', i, OUTPUT, PUSH_PULL);
	  }
  GPIO_Init('A', 7, INPUT, PULL_UP);
  KeyPad_Init();

  while (1)
  {
	 KeyPad_Manage();
  }
  return 0;
}


void KeyPad_CallOut_Button_Pressed_Notification()
{
	key = KeyPad_GetKey();
	Display_Key(key);
}
void Display_Key(unsigned char key)
{
	for (int i = 0; i < 7; i++)
    {
		GPIO_WritePin('A', i, (sevenSegTable[key] & (1 << i)) >> i);
    }

}



