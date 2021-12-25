#include <stdio.h>
#include <stdlib.h>

int main()
{
   float power;
   printf("Enter power of e \n");
   scanf("%f",&power);
   int terms;
   printf("Enter number of terms \n");
   scanf("%d",&terms);
   float expension=1;
   float answer=1;
   int i;
   for (i=1;i<=terms;i++){
    answer=(answer*power)/i;
    expension=expension+answer;

   }
   printf("%f",expension);
}
