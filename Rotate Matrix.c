/* Rotation	Trick / Steps
90° Clockwise -- Transpose → Reverse each row
90° Anticlockwise	 -- Transpose → Reverse each column
180° (same both ways) -- Reverse each row → Reverse the order of rows
270° Clockwise -- Same as 90° Anticlockwise
270° Anticlockwise -- Same as 90° Clockwise */

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    // Step 1: Transpose the matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < *matrixColSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][*matrixColSize - 1 - j];
            matrix[i][*matrixColSize - 1 - j] = temp;
        }
    }
}
