// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isLeafSymmetric(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    if (left->val != right->val) return false;
    return isLeafSymmetric(left->left, right->right) && isLeafSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return isLeafSymmetric(root->left, root->right);
}