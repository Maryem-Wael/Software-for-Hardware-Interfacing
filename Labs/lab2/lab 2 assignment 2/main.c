#include <stdio.h>

int main()
{
    int number_of_rows , counter1 , counter2 , space = 1;

    printf("Enter number of rows: \n");
    scanf("%d", &number_of_rows);

    space = number_of_rows - 1;

    for (counter1 = 1; counter1 <= number_of_rows; counter1++)
    {
        for (counter2 = 1; counter2 <= space; counter2++){
            printf(" ");
        }

        space--;

        for (counter2 = 1; counter2 <= 2*counter1-1; counter2++){
            printf("*");
        }

        printf("\n");
    }

    space = 1;

    for (counter1 = 1; counter1 <= number_of_rows - 1; counter1++)
    {
        for (counter2 = 1; counter2 <= space; counter2++){
            printf(" ");
        }


        space++;

        for (counter2 = 1 ; counter2 <= 2*(number_of_rows-counter1)-1; counter2++){
            printf("*");
        }


        printf("\n");
    }

    return 0;
}
