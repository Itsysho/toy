// Given a binary tree, determine if it is height-balanced.

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
    int dfs(TreeNode* root, bool &ret) {
        if (root == NULL || !ret) {
            return 0;
        }
        int l = dfs(root->left, ret);
        int r = dfs(root->right, ret);
        if (abs(l - r) > 1) {
            ret = false;
        }
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        dfs(root, ret);
        return ret;
    }
};