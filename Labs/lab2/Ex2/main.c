#include<stdio.h>
#include <stdlib.h>
#define INT_BITS 32



int main()
{
  int n ;
  int d ;
  unsigned char left_rotation,Right_rotation;
  printf("Enter 8 bits number=");
  scanf("%d" , &n);
  printf("Rotate by=");
  scanf("%d" , &d);
  left_rotation=(n << d)|(n >> (8 - d));
  Right_rotation=(n >> d)|(n << (8 - d));
  printf("left Rotation is %d \n",left_rotation);
  printf("right Rotation is %d \n",Right_rotation);
}

