
// @Title: 路径总和 (Path Sum)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-08 21:14:16
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
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root==NULL) 
        return false;
    int t = sum-root->val;
    
    if(!root->left&&!root->right&&t==0) 
        return true;
    
    return hasPathSum(root->left,t)||hasPathSum(root->right,t);
}
