
// @Title: 相同的树 (Same Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-27 21:52:33
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL&&q==NULL)
        return true;
    
    if(p==NULL || q==NULL)
        return false;
    
    if(p->val != q->val)
        return false;
    
    return isSameTree( p->left, q->left) & isSameTree( p->right, q->right );
}
