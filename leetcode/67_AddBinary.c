// Given two binary strings a and b, return their sum as a binary string.
char * addBinary(char * a, char * b){
    int lenA = strlen(a), lenB = strlen(b);
    int carry = 0;
    int ret*;
    int lenRet;
    int idx = lenC;
    ret[idx] = '\0';
    while (lenA > 0 || lenB > 0) {
        if (lenA > 0) {
            carry += a[--lenA]-'0';
        }
        if(lenB > 0) {
            carry += b[--lenB]-'0';
        }
        ret[--idx] = (carry % 2) + '0';
        carry /= 2;
    }
    if (carry > 0) {
        *char next = (char *) malloc(sizeof(char)*(lenC+2));
        next[0] = carry + '0';
        free(ret);
        ret = next;
    }
    return ret;
} 