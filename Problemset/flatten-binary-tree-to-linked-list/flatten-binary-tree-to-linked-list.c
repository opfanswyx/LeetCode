
// @Title: 二叉树展开为链表 (Flatten Binary Tree to Linked List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-15 19:06:20
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
typedef struct TreeNode tree;

tree* rightMost(tree* T) {
  if(T -> right != NULL) return rightMost(T -> right);
  return T;
}

tree* post(tree* T) {
  if(T == NULL) return NULL;
  if(T -> left == NULL) {
    T -> right = post(T -> right);
    return T;
  }
  rightMost(T -> left) -> right = T -> right;
  T -> right = post(T -> left);
  T -> left = NULL;
  return T;
}

void flatten(tree* root) {
  post(root);
}
