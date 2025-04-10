#include <stdio.h>

/* Floyd's Tortoise and Hare algorithm or Floyd's Cycle Detection algorithm:
The theory is is we can think of it like a maze we are sending two persons over, one is slow (moves one step at a time) and other one is fast(moves two steps at a time) like Tortoise and Hare respectively. 
So both start from the start when there is a duplicate in the maze (two paths(index) lead to same point(value)) then slow and fast will eventually meet in the loop but now we dont know 
which is the same point (duplicate value) so to find the duplicate we send the slow back to starting point and we set both of them at same speed (both moves one step at a time). 
now the fast will be revolving in the loop and slow will start from first now when slow and fast meet again, this is the same point (duplicate value which should be returned). */

int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];       
        fast = nums[nums[fast]]; 
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow]; 
        fast = nums[fast]; 
    }

    return slow; 
}
