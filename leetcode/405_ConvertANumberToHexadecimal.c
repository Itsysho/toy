// Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

// All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

// Note: You are not allowed to use any built-in library method to directly solve this problem.

void rec(char *ret, int* index, unsigned int num) {
    if (num == 0)
        return;
    rec(ret, index, num>>4);
    int d = num%16;
    ret[(*index)++] = d < 10 ? d + '0' : d-10 + 'a';
}

char* toHex(int num){
    char *ret = (char*) malloc(sizeof(char)*16);
    int index = 0;
    rec(ret, &index, num);
    ret[index] = '\0';
    if (num == 0) {
        ret[0] = '0';
        ret[1] = '\0';
    }
    return ret;
}