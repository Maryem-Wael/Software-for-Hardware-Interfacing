#include <stdio.h>
#include <stdlib.h>


int main()
{
    int num1;
    int num2;
    int num3;

    printf("please Enter the first number:\n");
    scanf("%d" , &num1);
    printf("please Enter the second number:\n");
    scanf("%d" , &num2);
    printf("please Enter the third number:\n");
    scanf("%d" , &num3);
    int sum = num1+num2+num3;
    int product = num1*num2*num3;
    float average = (num1+num2+num3)/3;
    int largest= num1<num2<num3?num3:num1<num2?num2:num1;
    int smallest=num1<num2<num3?num1:num2<num3?num2:num3;


    printf("The sum is %d" , sum );
    printf("\n The product is %d", product );
    printf("\n The average is %f", average );
    printf("\n The largest is %d", largest );
    printf("\n The smallest is %d", smallest );


}
