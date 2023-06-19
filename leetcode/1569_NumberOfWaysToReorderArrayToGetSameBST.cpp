// Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

// For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
// Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

// Since the answer may be very large, return it modulo 10^9 + 7.

class Solution {
private:
    vector<vector<long long>> C;
public:
    static const long long MOD = 1000000007;
    long long bst(vector<int>& nums) {
        // left.size + right.size = nums.size - 1
        // (nums.size - 1)! / ((left.size)! * (right.size)!) * numOfWays(left) * numOfWays(right)
        int n = nums.size();
        if (n <= 1)
            return 1; 
        vector<int> left;
        vector<int> right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        long long p = C[n-1][left.size()];
        return (p * bst(left)) % MOD * bst(right) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        // build Combination
        // C.clear();
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            vector<long long> p;
            p.push_back(1);
            for (int j = 1; j <= i; j++) {
                if (j != i)
                    p.push_back((C[i-1][j-1] + C[i-1][j])%MOD);
                else
                    p.push_back(1);
            }
            C.push_back(p);
        }
        return (bst(nums) - 1 + MOD) % MOD;
    }
};
