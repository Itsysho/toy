// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findMinimumDepth(struct TreeNode* root, int depth){
    if (root == NULL) 
        return 0x3f3f3f3f;

    if (root->left == NULL && root->right == NULL)
        return depth;
    
    int left = findMinimumDepth(root->left, depth + 1);
    int right = findMinimumDepth(root->right, depth + 1);
    return left < right ? left : right;
}

int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    return findMinimumDepth(root, 1);
}