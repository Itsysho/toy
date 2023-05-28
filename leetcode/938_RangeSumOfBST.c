// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high){
    int ret = 0;
    if (root == NULL)
        return 0;
    if (root->val >= low && root->val <= high) 
        ret += root->val;
    if (low <= root->val)
        ret += rangeSumBST(root->left, low, high);
    if (high >= root->val)
        ret += rangeSumBST(root->right, low, high);
    
    return ret;
}