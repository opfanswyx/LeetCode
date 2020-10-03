
// @Title: 二叉树的中序遍历 (Binary Tree Inorder Traversal)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-12 10:09:22
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(int *cnt, int **res, struct TreeNode* root)
{
    if (root == NULL)
        return;
    
    inorder(cnt, res, root->left);
    
    (*cnt)++;
    *res = realloc(*res, (*cnt)*sizeof(int));
    (*res)[*cnt - 1] = root->val;
    
    inorder(cnt, res, root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int cnt = 0;
    int *res = calloc(1, sizeof(int));
    inorder(&cnt, &res, root);
    
    *returnSize = cnt;
    return res;
}
