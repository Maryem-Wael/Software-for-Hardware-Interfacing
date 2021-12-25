#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    float u;
    float t;

    printf("please Enter the accleration:\n");
    /*take the number from the user*/
    scanf("%f" , &a);
    printf("please Enter the initial velocity:\n");
    scanf("%f" , &u);
    printf("please Enter the time:\n");
    scanf("%f" , &t);
    float velocity = u+a*t;
    float distance =u*t+0.5*a*t*t;

    printf("The velocity is %f" , velocity );
    printf("\n The distance is %f", distance );

}
