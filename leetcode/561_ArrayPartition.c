// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}


int arrayPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int ret = 0;
    for (int i = 0; i < numsSize; i += 2) {
        ret+=nums[i];
    }
    return ret;
}