//Learn merge sort
/*A pair (i, j) is a reverse pair if
- i < j and
- nums[i] > 2 * nums[j]*/

int merge(int* nums, int low, int mid, int high) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    // Merge two sorted halves
    int n = high - low + 1;
    int* temp = (int*)malloc(n * sizeof(int));
    int i = low, k = 0;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= high)
        temp[k++] = nums[j++];

    // Copy back to original array
    for (i = 0; i < n; i++)
        nums[low + i] = temp[i];

    free(temp);
    return count;
}

int mergeSort(int* nums, int low, int high) {
    if (low >= high) return 0;

    int mid = (low + high) / 2;
    int count = 0;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);

    return count;
}

int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
}
