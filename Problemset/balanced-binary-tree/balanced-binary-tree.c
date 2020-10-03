
// @Title: 平衡二叉树 (Balanced Binary Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-07 21:41:22
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
bool isBalanced(struct TreeNode* root) {
    bool ans = true;
    isBalancedHelper(root, &ans);
    return ans;
}

int isBalancedHelper(struct TreeNode * root, bool *answer) {
    if(!root) return 0;
    
    int left = isBalancedHelper(root -> left, answer);
    int right = isBalancedHelper(root -> right, answer);
    
    if(abs(left - right) > 1) {
        *answer = false;
    }
    
    return left > right ? left + 1 : right + 1;
}
