// 

class Solution {
public:
    int binaryGap(int n) {
        int i = 0;
        int prev = -1;
        int ret = 0;
        while (n) {
            if (n&1) {
                if (prev != -1)
                    ret = max(ret, i-prev);
                prev = i;
            }
            i++;
            n >>= 1;
        }
        return ret;
    }
};