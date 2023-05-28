// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

int majorityElement(int* nums, int numsSize){ 
    int ret = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
      if (nums[i] == ret) 
        count++;
      else
        count--;
      if (count == 0) {
        ret = nums[i];
        count = 1;
      }
    }
    return ret;
}
