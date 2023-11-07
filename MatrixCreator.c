#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int columns;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int columns) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;

    int hat[9];
    size_t n = 9;  
    size_t k;

    // srand(time(NULL));

    for (k = 0; k < n; k++) hat[k] = k;

    matrix->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (k = 0; k < 1; k++) {
                size_t pick = rand() % n;
                matrix->data[i][j] = hat[pick]+1;
                hat[pick] = hat[--n];
            }
        }
    }

    return matrix;
}

void destroyMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

Matrix*** createMatrixOfMatrices(int rows, int columns, int matrixRows, int matrixColumns) {
    Matrix*** matrixOfMatrices = (Matrix***)malloc(rows * sizeof(Matrix**));
    for (int i = 0; i < rows; i++) {
        matrixOfMatrices[i] = (Matrix**)malloc(columns * sizeof(Matrix*));
        for (int j = 0; j < columns; j++) {
            matrixOfMatrices[i][j] = createMatrix(matrixRows, matrixColumns);
        }
    }
    return matrixOfMatrices;
}

void destroyMatrixOfMatrices(Matrix*** matrixOfMatrices, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            destroyMatrix(matrixOfMatrices[i][j]);
        }
        free(matrixOfMatrices[i]);
    }
    free(matrixOfMatrices);
}


void printMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            printf("%d  ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void printMatrixOfMatrices(Matrix*** matrixOfMatrices, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Matrix[%d][%d]:\n", i, j);
            printMatrix(matrixOfMatrices[i][j]);
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    
    int rows = 3;
    int columns = 3;
    int matrixRows = 3;
    int matrixColumns = 3;

    Matrix*** myMatrixOfMatrices = createMatrixOfMatrices(rows, columns, matrixRows, matrixColumns);

    printf("Matrix of Matrices:\n");
    printMatrixOfMatrices(myMatrixOfMatrices, rows, columns);

    destroyMatrixOfMatrices(myMatrixOfMatrices, rows, columns);

    return 0;
}
