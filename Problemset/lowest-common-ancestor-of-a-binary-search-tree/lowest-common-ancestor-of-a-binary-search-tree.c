
// @Title: 二叉搜索树的最近公共祖先 (Lowest Common Ancestor of a Binary Search Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-16 15:15:46
// @Runtime: 12 ms
// @Memory: N/A

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(p->val==root->val) return p;
    else if(q->val==root->val) return q;
    else if(p->val>root->val&&q->val>root->val) return lowestCommonAncestor(root->right,p,q);
    else if(p->val<root->val&&q->val<root->val) return lowestCommonAncestor(root->left,p,q);
    else return root;
}
