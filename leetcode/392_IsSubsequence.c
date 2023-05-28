// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

bool isSubsequence(char * s, char * t){
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS > lenT)
        return false;
    
    int idx = 0;
    for (int i = 0; i < lenT; i++) {
        if (i >= idx && *s == t[i]) {
            idx++;
            s++;
        }
    }
    return idx == lenS;
}