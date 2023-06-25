// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // The maximum profit in day i with no any stock
        vector<int> dp0(n+1, 0);
        // The maximum profit in day i with one stock
        vector<int> dp1(n+1, 0);

        dp0[0] = 0;
        dp1[0] = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp1[i+1] = max(dp1[i], dp0[i]-fee-prices[i]);
            dp0[i+1] = max(dp0[i], dp1[i]+prices[i]);
        }
        return dp0[n];
    }
};