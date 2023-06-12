// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

void moveZeroes(int* nums, int numsSize){
    int pre = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[pre];
            nums[pre] = temp;
            pre++;   
        }
    }
}