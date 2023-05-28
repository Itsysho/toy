// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int findLucky(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmpfunc);
    int ret = -1;
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (i == 0 || arr[i] == arr[i - 1]){ 
            count++;
        } else {
            if (arr[i - 1] == count) 
                ret = count;
            count = 1;
        }
    }
    if (count == arr[arrSize - 1]) {
        ret = arr[arrSize - 1];
    }
    return ret;
}