#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

// Function to check if a number is safe to place in the grid
int isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Check if the number is not already present in the row and column
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    // Check if the number is not present in the 3x3 subgrid
    int subgridSize = 3;
    int startRow = row - (row % subgridSize);
    int startCol = col - (col % subgridSize);
    for (int i = 0; i < subgridSize; i++) {
        for (int j = 0; j < subgridSize; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }

    // If the number is safe, return 1
    return 1;
}

// Function to generate a random Sudoku grid
int generateSudoku(int board[SIZE][SIZE]) {
    int row, col;
    int num;
    int unassigned = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board with zeros
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            board[row][col] = 0;
        }
    }

    // Fill the diagonal subgrids with random values
    for (int subgrid = 0; subgrid < SIZE; subgrid += 3) {
        for (num = 1; num <= SIZE; num++) {
            do {
                row = subgrid + rand() % 3;
                col = subgrid + rand() % 3;
            } while (board[row][col] != 0);
            board[row][col] = num;
        }
    }

    // Fill the remaining grid using a backtracking approach
    if (!solveSudoku(board)) {
        return 0;
    }

    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    if (!findUnassignedLocation(board, &row, &col)) {
        return 1; // All cells are assigned, Sudoku is solved
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return 1;
            }
            board[row][col] = 0; // Unassign the cell if no solution found
        }
    }

    return 0; // No solution exists
}

// Function to find an unassigned location in the grid
int findUnassignedLocation(int board[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1; // Unassigned location found
            }
        }
    }
    return 0; // No unassigned location exists
}

int main() {
    int board[SIZE][SIZE];

    if (generateSudoku(board)) {
        // Printing the resulting Sudoku grid
        for (int i = 0; i < SIZE; i++) {
            if(i % 3 == 0) {
              printf("\n");
            }
            for (int j = 0; j < SIZE; j++) {
              if(j % 3 == 0) {
                printf("  ");
              }
                printf("%d ", board[i][j]);
            }
            
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
