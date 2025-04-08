#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(numRows * sizeof(int*)); //create result matrix 
    int* colSizes = (int*)malloc(numRows * sizeof(int)); //create col array to store colsize for each row

    for (int i = 0; i < numRows; i++) {
        colSizes[i] = i + 1; //each row has i+1 columns
        result[i] = (int*)malloc(colSizes[i] * sizeof(int)); //for each row create columns of colsize

      //first and last element always 1
        result[i][0] = 1; 
        result[i][i] = 1;

        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j]; //an element m[r][c] is m[r-1][c] (above element in previous row} and m[r-1][c-1] (element before above element in previous row)
        }
    }

    *returnSize = numRows;
    *returnColumnSizes = colSizes;
    return result;
}

#include <stdio.h>

int main() {
    int numRows;
    int returnSize;
    int* returnColumnSizes;

    scanf("%d",&numRows);
    
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
        free(triangle[i]);
    }

    free(triangle);
    free(returnColumnSizes);
    return 0;
}
