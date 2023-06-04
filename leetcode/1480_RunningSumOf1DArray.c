// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    * returnSize = numsSize;
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum += nums[i];
        nums[i] = sum;
    }
    return nums;
}