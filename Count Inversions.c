#include <stdio.h>

/* A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:
1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j' */

long long getInversions(long long *arr, int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]> arr[j]) count++;
        }
    }
    return count;
}

//works but not optimized. optimized version is using merge sort.
