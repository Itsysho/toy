// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *ret = (int*) malloc(sizeof(int) * 1);
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        int *next = (int*) malloc(sizeof(int) * (i + 1));
        next[0] = 1;
        for (int j = 1; j < i; j++) {
            next[j] = ret[j] + ret[j-1];
        }
        next[i] = 1;
        free(ret);
        ret = next;
    }
    *returnSize = rowIndex + 1;
    return ret;
}119. Pascal's Triangle II
