// Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

// In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

// If there is no way to make arr1 strictly increasing, return -1.

class Solution {
public:
    int dfs(vector<int>& arr1, vector<int>& arr2, vector<unordered_map<int, int>>& dp, int i, int prev) {
        int n = arr1.size();
        if (i == n)
            return 0;
        auto found = dp[i].find(prev);
        if (found != dp[i].end())
            return found->second;
        
        int replace_idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        int ret = INT_MAX;
        if (replace_idx != arr2.size()) {
            int replace = dfs(arr1, arr2, dp, i+1, arr2[replace_idx]);
            if (replace != INT_MAX) 
                ret = min(ret, replace + 1);
        }

        if (arr1[i] > prev)
            ret = min(ret, dfs(arr1, arr2, dp, i+1, arr1[i]));

        return dp[i][prev] = ret;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(), arr2.end());
        // map is BST, unordered_map is hash
        // dp[i][(i-1)-th value] = min #operation
        vector<unordered_map<int, int>> dp(n + 1);
        
        int ret = dfs(arr1, arr2, dp, 0, INT_MIN);
        return ret == INT_MAX ? -1 : ret;
    }
};