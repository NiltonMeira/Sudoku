#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int initial_matrix[3][3];

    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            loop: ;
            int aleatory_number = (rand() % 9) + 1;
            printf("%d \n", aleatory_number);

            for (int k = 0; k < 9; k++)
            {
                if (aleatory_number == numbers[k])
                {
                    initial_matrix[i][j] = aleatory_number;
                    numbers[aleatory_number - 1] = 10;
                }
                else
                {
                    goto loop;
                }
            
            }
        }
    }

        for (int i = 0; i < 3; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                printf("%d", initial_matrix[i][j]);
            }
        }
}