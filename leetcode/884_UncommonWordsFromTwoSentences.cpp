// A sentence is a string of single-space separated words where each word consists only of lowercase letters.

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        set<string> u1;
        set<string> u2;
        map<string, int> count;
        stringstream sin1(s1);
        string x;
        while (sin1 >> x)   u1.insert(x), count[x]++;
        stringstream sin2(s2);
        while (sin2 >> x)   u2.insert(x), count[x]++;
        vector<string> ret;
        for (const string& s : u1) {
            if(u2.find(s) == u2.end() && count[s] == 1) {
                ret.push_back(s);
            }
        }
        for (const string& s : u2) {
            if(u1.find(s) == u1.end() && count[s] == 1) {
                ret.push_back(s);
            }
        }
        return ret;
    }
};