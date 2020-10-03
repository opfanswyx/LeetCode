
// @Title: 从前序与中序遍历序列构造二叉树 (Construct Binary Tree from Preorder and Inorder Traversal)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-14 10:15:02
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

// return the position (index) of the val in the array
int find_in_array(int *a, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (a[i] == val) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (inorderSize == 0 || preorderSize == 0) {
        return NULL;
    }
    // the first of pre-order must be the root
    int root = preorder[0];
    
    // now in the inorder array, the elements to the left of root must be in the left sub-tree, and right vise-vesa
    int root_index = find_in_array(inorder, inorderSize, root);
    
    struct TreeNode *ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    ret->val = root;
    ret->left = NULL;
    ret->right = NULL;
    
    if (root_index > 0) {
        ret->left = buildTree(&preorder[1], root_index, &inorder[0], root_index);
    }
    if (root_index < inorderSize - 1) {
        ret->right = buildTree(&preorder[1 + root_index], inorderSize - root_index - 1, &inorder[root_index + 1], inorderSize - root_index - 1);
    }
    
    return ret;
}
