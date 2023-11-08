#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int *create_array()
{
    int *array_full = (int *)malloc(81 * sizeof(int)); // Aloca memória para o array
    if (array_full == NULL)
    {
        printf("Falha na alocação de memória\n");
        exit(1);
    }

teste:

    for (int i = 0; i < 9; i++)
    {
        int array_hor[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        shuffle(array_hor, 9);
        // validation(array_full);

        for (int j = 0; j < 9; j++)
        {
            array_full[i * 9 + j] = array_hor[j];
        }
    }
    // acessar pela coluna array_full[(linha-1)*9 + coluna-1]

    int sum_validation = 0;

    for (int i = 1; i < 10; i++)
    {
        int sum = 0;
        for (int j = 1; j < 10; j++)
        {
            sum += array_full[(j - 1) * 9 + i - 1];
        }
        if (sum == 45)
        {
            sum_validation++;
        }
    }
    if (sum_validation == 9)
    {
        return array_full;
    }
    else
    {
        goto teste;
    }
}

void print_array(int *array_full)
{
    for (int i = 0; i < 9; i++)
    {
        printf("\n");
        if (i % 3 == 0)
        {
            printf("\n");
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                printf("  ");
            }
            printf("%d  ", array_full[i * 9 + j]);
        }
    }
}

int main()
{
    srand(time(NULL));

    int *new_array = create_array();
    print_array(new_array);

    // acessar pela coluna array_full[(linha-1)*9 + coluna-1]
    printf("%d", new_array[(3 - 1) * 9 + 1 - 1]);

    free(new_array);

    return 0;
}