// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int arr[1001] = {};
    for (int i = 0;i < nums1Size; i++) {
        arr[nums1[i]] |= 1;
    }
    for (int i = 0;i < nums2Size; i++) {
        arr[nums2[i]] |= 2;
    }
    *returnSize = 0;
    for (int i = 0;i <= 1000; i++) {
        if (arr[i] == 3) {
            (*returnSize)++;
        }
    }
    int *ret =  (int*)malloc(*returnSize * sizeof(int));
    int idx = 0;
    for (int i = 0; i <= 1000; i++) {
        if (arr[i] == 3) {
            ret[idx] = i;
            idx++;
        }
    }
    return ret;
}