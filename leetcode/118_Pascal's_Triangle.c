// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//      1
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1

**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(numRows * sizeof(int*));
    *returnSize = numRows;
    *returnColumnSizes = (int*) malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        ret[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                ret[i][j] = 1;
            else
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    return ret;
}

