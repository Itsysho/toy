// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum(struct TreeNode* root, int pathSum, int target) {
    if (root == NULL)
        return 0;
    pathSum += root->val;
    if (root->left == NULL && root->right == NULL)
        return pathSum == target;
    return sum(root->left, pathSum, target) || sum(root->right, pathSum, target);
} 
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) return false; 
    return sum(root, 0, targetSum);
}
