// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream sin(s);
        string last;
        while (sin >> s) {
            last = s;
        }
        return last.length();
    }
};