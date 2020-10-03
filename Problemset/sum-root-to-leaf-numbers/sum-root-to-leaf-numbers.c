
// @Title: 求根到叶子节点数字之和 (Sum Root to Leaf Numbers)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 11:31:48
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
int sum_tree(struct TreeNode* root,int sum)
 {
     if(root == NULL) return 0;
     sum = sum *10 + root->val;
     int ret = sum_tree(root->left,sum) + sum_tree(root->right,sum);
     return ret==0?sum:ret;
 }

int sumNumbers(struct TreeNode* root) {
    return sum_tree(root,0);
}
