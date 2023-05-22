// Given the root of a binary tree, return the postorder traversal of its nodes' values.

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

int sizeofTree(struct TreeNode* root){
    if (root == NULL)
        return 0;

    return sizeofTree(root->left) + sizeofTree(root->right) + 1;
}

void traversal(struct TreeNode* root, int* ret, int* returnSize){
    if (root == NULL)
        return;

    traversal(root->left, ret, returnSize);
    traversal(root->right, ret, returnSize);
    ret[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = sizeofTree(root);
    int* ret = (int*)malloc((size) * sizeof(int));
    *returnSize = 0;
    traversal(root, ret, returnSize);
    return ret;
}