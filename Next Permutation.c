/* If there is an array [1,2,3] then its permutations arranged in lexicographical order is [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
so the next permutation of [1,3,2] is [2,1,3] and for [3,2,1] there is no next permutation so we should return [1,2,3] (its reverse since last is always descending its next would be asc)

🧠 Example:
Input: [1, 3, 5, 4, 2]
- Step 1: Find dip → 3 < 5 → index = 1
- Step 2: Find just bigger → 4 (at index 3)
- Step 3: Swap → [1, 4, 5, 3, 2]
- Step 4: Reverse after index 1 → [1, 4, 2, 3, 5]
Output: [1, 4, 2, 3, 5] ✅*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = numsSize - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    reverse(nums, i + 1, numsSize - 1);
}

