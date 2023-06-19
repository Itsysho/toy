// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;
        int m = (l + r)/2;
       TreeNode* ret = new TreeNode(nums[m]);
       ret->left = buildBST(nums, l, m-1);
       ret->right = buildBST(nums, m+1, r);
       return ret;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
};