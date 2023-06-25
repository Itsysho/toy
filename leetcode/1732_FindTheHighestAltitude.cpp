// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0;
        int h = 0;
        for (int &p : gain) {
            h += p;
            ret = max(h, ret);
        }
        return ret;
    }
};