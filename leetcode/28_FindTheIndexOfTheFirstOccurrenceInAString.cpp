// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hl = haystack.length();
        int nl = needle.length();
        if (nl == 0 || nl > hl) return -1;
        int m = hl - nl + 1;
        for (int i = 0; i < m; i++) {
            int match = true;
            for (int j = 0; j < nl; j++) {
                if (needle[j] != haystack[i+j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }
};