// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

int cmpfunc(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int largestPerimeter(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int ret = 0;
    for (int i = 2;i < numsSize;i++) {
        if ((nums[i - 2] + nums[i - 1]) > nums[i] ) {
            ret = nums[i - 2] + nums[i - 1] + nums[i];
        }
    }
    return ret;
}