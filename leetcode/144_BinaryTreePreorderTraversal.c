// Given the root of a binary tree, return the preorder traversal of its nodes' values.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int treeSize(struct TreeNode* root){
    if (root == NULL)
        return 0;
    return treeSize(root->left) + treeSize(root->right) + 1;
}

void traversal(struct TreeNode* root, int* ret, int* returnSize){
    if (root == NULL)
        return;

    ret[(*returnSize)++] = root->val;
    traversal(root->left, ret, returnSize);
    traversal(root->right, ret, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = treeSize(root);
    int* ret = (int*)malloc((size) * sizeof(int));
    *returnSize = 0;
    traversal(root, ret, returnSize);
    return ret;
}