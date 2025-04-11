/*✅ malloc() — Memory ALLOCation
Syntax:
ptr = (int*) malloc(n * sizeof(int));
- Allocates a block of memory of n elements.
- The memory is uninitialized (can contain garbage values).
- Has only one parameter which is total bytes (n * size)

✅ calloc() — Contiguous ALLOCation
Syntax:
ptr = (int*) calloc(n, sizeof(int));
- Allocates memory for n elements of size sizeof(int).
- Initializes all elements to zero (clean slate).
- Has 2 parameters which are num of blocks , size of each (n,size)*/

#include <stdlib.h>

int* repeatedNumber(const int* A, int n1, int *len1) {
    int* count = (int*)calloc(n1 + 1, sizeof(int)); // to count occurrences
    int* res = (int*)malloc(2 * sizeof(int));       // to return [duplicate, missing]
    int i;
    *len1 = 2;

    for (i = 0; i < n1; i++) {
        count[A[i]]++;
    }

    for (i = 1; i <= n1; i++) {
        if (count[i] == 2) res[0] = i;  // duplicate
        if (count[i] == 0) res[1] = i;  // missing
    }

    free(count);
    return res;
}

