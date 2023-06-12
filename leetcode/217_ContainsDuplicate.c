// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

int cmpfunc(void* a, void* b) {
    return *(int*)a - *(int*)b;
}
bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}