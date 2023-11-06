#include <stdio.h>

typedef struct {
    int rows;
    int columns;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int columns) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;

    // Allocate memory for the matrix data
    matrix->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(columns * sizeof(int));
    }

    // Initialize the matrix elements (you can do this as needed)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix->data[i][j] = 0; // Initialize to some default value
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
            printf("%d\t", matrix->data[i][j]);
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
    int rows = 3;
    int columns = 3;
    int matrixRows = 3;
    int matrixColumns = 3;

    Matrix*** myMatrixOfMatrices = createMatrixOfMatrices(rows, columns, matrixRows, matrixColumns);
    // Initialize or modify the individual matrices as needed

    // Print the matrix of matrices
    printf("Matrix of Matrices:\n");
    printMatrixOfMatrices(myMatrixOfMatrices, rows, columns);

    // Don't forget to free the memory when you're done
    destroyMatrixOfMatrices(myMatrixOfMatrices, rows, columns);

    return 0;
}
