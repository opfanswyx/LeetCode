
// @Title: 翻转二叉树 (Invert Binary Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-15 16:16:09
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
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL)
        return root;
    
    struct TreeNode* temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
#if 0
void swap(struct TreeNode* T){
    if(T==NULL)
        return;
    struct TreeNode* temp;
    temp=T->left;
    T->left=T->right;
    T->right=temp;
    swap(T->left);
    swap(T->right);
}
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL)
        return root;
    swap(root);
    return root;
}
#endif
