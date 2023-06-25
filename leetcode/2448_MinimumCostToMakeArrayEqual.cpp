// You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

// You can do the following operation any number of times:

// Increase or decrease any element of the array nums by 1.
// The cost of doing one operation on the ith element is cost[i].

// Return the minimum total cost such that all the elements of the array nums become equal.

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = make_pair(nums[i], cost[i]);
            sum += cost[i];
        }
        sort(arr.begin(), arr.end());
        long long mid = sum/2;
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            mid -= arr[i].second;
            if (mid < 0) {
                for (int j = 0; j < n; j++) {
                    ret += (long long)cost[j]*abs(arr[i].first - nums[j]);
                }
                break;
            }
        }
        return ret;
    }
};