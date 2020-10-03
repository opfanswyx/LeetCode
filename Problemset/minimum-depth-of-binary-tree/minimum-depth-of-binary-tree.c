
// @Title: 二叉树的最小深度 (Minimum Depth of Binary Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-08 21:03:04
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
int minDepth(struct TreeNode* root) {
   if(root==NULL)
       return 0;
    if(root->left==NULL)
        return minDepth(root->right)+1;
    if(root->right==NULL)
        return minDepth(root->left)+1;
    
    int lleft=minDepth(root->left);
    int lright=minDepth(root->right);
    
    return lleft>lright?lright+1:lleft+1;
}
