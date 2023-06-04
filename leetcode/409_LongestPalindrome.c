// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

int longestPalindrome(char * s){
    int comm[128] = {0};
    int lenS = strlen(s);
    for (int i = 0; i < lenS; i++) {
        comm[s[i]] += 1;
    }
    int ret = 0;
    int odd = 0;
    for (int i = 0; i < 128; i++) {
        if (comm[i] % 2 == 0) {
            ret += comm[i];
        } else {
            odd = 1;
            ret += (comm[i] - 1);
        } 
    }
    ret += odd;
    return ret;
}