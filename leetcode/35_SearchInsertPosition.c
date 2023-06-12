// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// sol. 1
int searchInsert(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize - 1;
    int ret = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            return m;
        } else if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
        ret = l;
    }
    return ret;
}

// sol. 2
int searchInsert(int* nums, int numsSize, int target){
    if (target <= nums[0]) return 0;
    for (int i = 1; i < numsSize; i++) {
        if (target > nums[i - 1] && target <= nums[i]) {
            return i;
        }
    }    
    return numsSize;
}