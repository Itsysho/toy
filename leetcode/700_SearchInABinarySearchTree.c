// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// sol 1
struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (root->val == val) return root;
    if (root->val < val && root->right != NULL)
        return searchBST(root->right, val);
    if (root->val > val && root->left != NULL)
        return searchBST(root->left, val);
    
    return NULL;
}
// sol 2
struct TreeNode* searchBST(struct TreeNode* root, int val){
    while (root != NULL) {
        if (root->val == val)
            return root;
        if (root-> val < val)
            root = root->right;
        else
            root = root->left; 
    } 
    return NULL;
}