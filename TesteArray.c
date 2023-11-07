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

int main(){
    srand(time(NULL));

    // int array_hor[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // for(int j = 0; j < 9; j++){
    //     shuffle(array_hor, 9);
    //     if(j % 3 == 0){
    //         printf("\n");
    //     }
    //     for(int i = 0; i < 9; i++){
    //         if(i % 3 == 0){
    //             printf("  ");
    //         }
    //         printf("%d  ", array_hor[i]);
    //     }
    //     printf("\n");
    // }

    int array_full[81];

    for(int i = 0; i < 9; i++)
    {
        int array_hor[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        shuffle(array_hor, 9);
        
        for(int j = 0; j < 9; j++)
        {
            array_full[i*9+j] = array_hor[j];
        }
    }

    for(int i = 0; i < 9; i++)
    {
        printf("\n");
        if(i % 3 == 0){
            printf("\n");
        }
        for(int j = 0; j < 9; j++)
        {
            if(j % 3 == 0){
                printf("  ");
            }
            printf("%d  ", array_full[i*9+j]);
        }
    }
    
    //acessar pela coluna array_full[(linha-1)*9 + coluna-1]
    printf("%d", array_full[(3-1)*9+1-1]);

    return 0;
}