// Comparison function to sort intervals by start time
int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    // Sort intervals by start
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** res = malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;

    for (int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If res is empty or no overlap
        if (*returnSize == 0 || res[*returnSize - 1][1] < start) {
            res[*returnSize] = malloc(sizeof(int) * 2);
            res[*returnSize][0] = start;
            res[*returnSize][1] = end;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        } else {
            // Merge: Update the end time to the max of both
            if (res[*returnSize - 1][1] < end)
                res[*returnSize - 1][1] = end;
        }
    }

    return res;
}
