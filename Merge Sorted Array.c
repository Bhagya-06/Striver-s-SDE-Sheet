#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for(int i=0; i<nums2Size; i++){
        nums1[m+i] = nums2[i]; // copy nums2 elements in nums1 starting from nums1size (m) plus i (index of nums2 element)
    }
//Bubble sort nums1 array after merge
    for (int i=0; i<nums1Size-1; i++){
        for(int j=0; j<nums1Size-i-1; j++){
            if(nums1[j]>nums1[j+1]){
                int temp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = temp;
            }
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main() {
    int nums1[10] = {5, 8, 9, 0, 0, 0};  // m = 3
    int nums2[] = {1, 3, 7};             // n = 3

    merge(nums1, 6, 3, nums2, 3, 3);

    printf("Merged array:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
