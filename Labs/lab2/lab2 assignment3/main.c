#include <stdio.h>
#include <stdlib.h>

int main()
{   int n, num1=0, num2=1, sum=0;

    printf("Enter number of terms\n");
    scanf("%d", &n);
    printf("%d,%d ", num1,num2);
    sum= num1+num2;
    for (int i=1; i<=n-2; i++)
    {
        num1=num2;
        num2=sum;
        sum= num1+num2;
    printf("%d,", sum);
    }



   return 0;
}
