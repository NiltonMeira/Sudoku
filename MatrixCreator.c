#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int columns;
    int** data;
} Matrix;

int generate_num(){
    int my_num;

}

Matrix* createMatrix(int rows, int columns) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;

    int hat[9];        // pool of numbers
    size_t n = 9;      // size of pool
    size_t k;

    srand(time(NULL));

    for (k = 0; k < n; k++) hat[k] = k;
    // Allocate memory for the matrix data
    matrix->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(columns * sizeof(int));
    }

    // Initialize the matrix elements (you can do this as needed)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (k = 0; k < 1; k++) {
                size_t pick = rand() % n;
                matrix->data[i][j] = hat[pick]+1; // Initialize to some default value
                hat[pick] = hat[--n];
            }
        }
    }

    return matrix;
}

// int **create_matrix()
// {   
//   // allocate Rows rows, each row is a pointer to int
//     int **initial_matrix = (int **)malloc(3 * sizeof(int *)); 
//     int row;

//     // for each row allocate Cols ints
//     for (row = 0; row < 3; row++) {
//         initial_matrix[row] = (int *)malloc(3 * sizeof(int));
//     }


//     int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//     srand(time(NULL));

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {   
//             loop: ;
//             int aleatory_number = (rand() % 9) + 1;
//             int check = 0;
        

//             for (int k = 0; k < 9; k++)
//             {
//                 if (aleatory_number == numbers[k])
//                 {
//                     initial_matrix[i][j] = aleatory_number;
//                     numbers[aleatory_number - 1] = 10;
//                     check = 1;
//                 }
//             }

//             if (check == 0)
//             {
//                 goto loop;
//             }
//         }
//     }  


//     return initial_matrix;
// }

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
