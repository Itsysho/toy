// Given a string s, return the number of segments in the string.

// A segment is defined to be a contiguous sequence of non-space characters.

int countSegments(char * s){
    int lenS = strlen(s);
    int ret = 0;
    int idx = 0;
    while (idx < lenS) {
        while(s[idx] == ' ')
            idx++;
        if (idx < lenS) {
            ret++;
            while (idx < lenS && s[idx] != ' ')
                idx++; 
        }
    }
    return ret;
}