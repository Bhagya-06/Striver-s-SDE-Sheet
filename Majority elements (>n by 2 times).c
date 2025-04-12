/* Steps:
- If an element is a majority, it appears more than all others combined.
- So, we increase count if current number matches candidate, otherwise decrease.
- When count drops to 0, we switch to a new candidate.
- The majority element survives this process.*/

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }
    return candidate;
}
