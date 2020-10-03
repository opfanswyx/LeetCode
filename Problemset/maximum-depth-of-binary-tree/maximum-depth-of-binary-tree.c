
// @Title: 二叉树的最大深度 (Maximum Depth of Binary Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-28 21:59:11
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int i=1;
int j=1;
int maxDepth(struct TreeNode* root) {
    if(root==NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left>right?left+1:right+1);
}
