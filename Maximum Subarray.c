/*Kadane's Algorithm: 
Kadane's Algorithm is the most efficient way to solve the Maximum Subarray Sum problem, where you need to find the contiguous subarray within a one-dimensional array that has the largest sum.

You loop through the array while tracking the current sum of elements.
- If the current sum becomes negative, start fresh from the current element.
- Always update max if sum is greater*/

int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0], max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (sum < 0)
            sum = nums[i];
        else
            sum += nums[i];

        if (sum > max)
            max = sum;
    }

    return max;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int result = maxSubArray(nums, n);
    printf("Maximum Subarray Sum: %d\n", result);

    return 0;
}
