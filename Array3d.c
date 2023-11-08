#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int size) {
    if (size > 1) {
        for (int i = size - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

int main() {
    int array_full[9][9];

    srand(time(NULL));

    for (int j = 0; j < 9; j++) {
        int array_ver[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        shuffle(array_ver, 9);

        for (int i = 0; i < 9; i++) {
            array_full[i][j] = array_ver[i];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", array_full[i][j]);
        }
        printf("\n");
    }

    return 0;
}
