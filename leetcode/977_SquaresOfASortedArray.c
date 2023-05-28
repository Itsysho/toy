// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        nums[i] *= nums[i];
    }
    *returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums;
}