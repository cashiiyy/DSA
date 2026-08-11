//created for leetcode 2 sum

#include <stdio.h>
#include <stdlib.h>

int search(int arr[],int n, int target) {
    for (int i=0;i<n;i++) {
        if (arr[i]==target) {
            return i;
        }
    }
    return -1;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i=0;
    int temp;
    while(i<numsSize) {
        temp=nums[i];
        int temp2=search(nums,numsSize,(target-temp));
        if (temp2!=-1 && temp2 !=i) {
            int * result = (int*)malloc(2*sizeof(int));
            result[0]=i;
            result[1]=temp2;
            *returnSize=2;
            return result;
            break;
        }
        else {
            i++;
        }
    }
        *returnSize=0;
        return NULL;
}