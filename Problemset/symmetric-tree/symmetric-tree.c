
// @Title: 对称二叉树 (Symmetric Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-27 22:25:30
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
bool dfs(struct TreeNode* rt1, struct TreeNode* rt2){
    if((rt1==NULL)&&(rt2==NULL))
        return true;
    if((rt1==NULL)||(rt2==NULL))
        return false;
    if(rt1->val!=rt2->val)
        return false;
    return dfs(rt1->left, rt2->right)&&dfs(rt1->right, rt2->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
        return true;
    
    return dfs(root->left, root->right);
}
