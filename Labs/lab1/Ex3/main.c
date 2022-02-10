#include <stdio.h>
#include <stdlib.h>


int main()
{
    int seconds;

    printf("please Enter the time in seconds:\n");
    /*take the number from the user*/
    scanf("%d" , &seconds);
    int hours=seconds/(60*60);
    int minutes=(seconds-hours*60*60)/60;
    int second=(seconds-minutes*60-hours*60*60);

    printf("The time is %d:%d:%d" , hours,minutes,second );


}
