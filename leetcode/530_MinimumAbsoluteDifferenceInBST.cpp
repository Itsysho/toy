// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

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
    // min, max
    pair<int, int> dfs(TreeNode* root, int &ret) {
        pair<int, int> range = make_pair(root->val, root->val);
        if (root->left != NULL) {
            pair<int, int> l = dfs(root->left, ret);
            ret = min(ret, root->val - l.second);
            range.first = l.first;
        }


        if (root->right != NULL) {
            pair<int, int> r = dfs(root->right, ret);
            ret = min(ret, r.first - root->val);
            range.second = r.second;
        }
        return range;
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ret = INT_MAX;
        dfs(root, ret);
        return ret;
    }
};