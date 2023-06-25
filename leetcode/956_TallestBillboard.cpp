// You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

// You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

// Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for (int &r : rods ) {
            sum += r;
        }
        int n = sum + 1;
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int rod: rods) {
            vector<int> dpTemp(n);
            copy(dp.begin(), dp.end(), dpTemp.begin());

            for (int i = 0; i <= sum - rod; i++) {
                if (dpTemp[i] < 0) continue;
                dp[i + rod] = max(dp[i + rod], dpTemp[i]);
                int idx = abs(i - rod);
                dp[idx] = max(dp[idx], dpTemp[i] + min(i, rod));
            }
        }
        return dp[0];
    }
};