// You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.

// At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.

// Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).

// Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 10^9 + 7.

class Solution {
public:
    static const int MOD = 1000000007;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        // vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        int dp[100][201] = {};
        dp[start][fuel] = 1;
        // i 剩餘油量
        for (int i = fuel; i >= 0; i--) {
            // form j to k
            for (int j = 0; j < n; j++) {
                int w = dp[j][i];
                if (w == 0)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (j == k)
                        continue;
                    int f = i - abs(locations[j] - locations[k]);
                    if (f >= 0) {
                        dp[k][f] += w;
                        if (dp[k][f] >= MOD)
                            dp[k][f] -= MOD;
                    }
                }
            }
        }
        int ret = 0;
        for (int i = 0; i <= fuel; i++) {
            ret += dp[finish][i];
            if (ret >= MOD)
                ret -= MOD;
        }
        return ret;
    }
};