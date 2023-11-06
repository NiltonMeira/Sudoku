#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **create_matrix()
{   
  // allocate Rows rows, each row is a pointer to int
    int **initial_matrix = (int **)malloc(3 * sizeof(int *)); 
    int row;

    // for each row allocate Cols ints
    for (row = 0; row < 3; row++) {
        initial_matrix[row] = (int *)malloc(3 * sizeof(int));
    }


    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            loop: ;
            int aleatory_number = (rand() % 9) + 1;
            int check = 0;
        

            for (int k = 0; k < 9; k++)
            {
                if (aleatory_number == numbers[k])
                {
                    initial_matrix[i][j] = aleatory_number;
                    numbers[aleatory_number - 1] = 10;
                    check = 1;
                }
            }

            if (check == 0)
            {
                goto loop;
            }
        }
    }  


    return initial_matrix;
}

int main()
{
    int **teste = create_matrix();
    for (int i = 0; i < 3; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                printf("%d", teste[i][j]);
            }
        }
}