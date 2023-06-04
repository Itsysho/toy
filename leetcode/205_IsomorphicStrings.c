// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

bool isIsomorphic(char * s, char * t){
    int table[128] = {};
    int t_used[128] = {};
    int count = 0;
    int len = strlen(s);
    while (count < len) {
        if (table[s[count]] == t[count]) {
            count++;
        } else if (table[s[count]] == 0) {
            table[s[count]] = t[count];
            if (t_used[t[count]])
                return false;
            t_used[t[count]] = 1;
            count++;
        } else {
            return false;
        } 
    }
    return true;
}