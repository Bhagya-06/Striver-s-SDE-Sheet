#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int marki[50] = {0}, markj[50] = {0}; //to mark i and j to be zeroed
    int iele = 0, jele = 0; //index to append to an array in c

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                marki[iele++] = i; //marking i
                markj[jele++] = j; //marking j 
            }
        }
    }

    for (int k = 0; k < iele; k++) {
        int row = marki[k];
        for (int j = 0; j < matrixColSize[row]; j++) {
            matrix[row][j] = 0; //set the row to 0
        }
    }

    for (int k = 0; k < jele; k++) {
        int col = markj[k];
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][col] = 0; // set the col to 0
        }
    }
}

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int** matrix = (int**)malloc(rows * sizeof(int*)); //dynamic allocation of 2D matrix 

    int* matrixColSize = (int*)malloc(rows * sizeof(int));//dynamic allocation array for matrixColSize

    for (int i = 0; i < rows; i++) {
        printf("Enter number of columns in row %d: ", i);
        scanf("%d", &matrixColSize[i]);  //input of columns to rows(each row can have different number of columns)

        matrix[i] = (int*)malloc(matrixColSize[i] * sizeof(int));  // allocate space for this row

        printf("Enter elements of row %d: ", i);
        for (int j = 0; j < matrixColSize[i]; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    setZeroes(matrix, rows, matrixColSize);

  // Output
    printf("\nMatrix after setZeroes:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}

