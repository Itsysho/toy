// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc(void* a, void* b){
    return *(int*)a - *(int*)b;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* ret = (int*)malloc(sizeof(int) * size);
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    int idx = 0;
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < nums1Size && idx2 < nums2Size) {
        if (nums1[idx1] < nums2[idx2]) {
            idx1++;
        } else if (nums1[idx1] > nums2[idx2]) {
            idx2++;
        } else {
            ret[idx] = nums1[idx1];
            idx1++;
            idx2++;
            idx++;
        }
    }
    *returnSize = idx;
    return ret;
}