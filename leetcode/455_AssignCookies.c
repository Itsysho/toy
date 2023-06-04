// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

int cmpfunc(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);
    int ret = 0;
    int i = 0;
    int j = 0;
    while (i < gSize && j < sSize) {
        if(g[i] <= s[j]) {
            ret++;
            i++;
            j++;
        } else {
            j++;
        }
    } 
    return ret;
}