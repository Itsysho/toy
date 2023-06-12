// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

int firstUniqChar(char * s){
    int lenS = strlen(s);
    int count[128] = {};
    for (int i = 0; i < lenS; i++) {
        count[s[i]]++;
    }
    for (int i = 0; i < lenS; i++) {
        if (count[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}