
// @Title: 验证二叉搜索树 (Validate Binary Search Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-12 10:16:12
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
struct min_max{
    int min;
    int max;
};

bool isBST(struct TreeNode* root, struct min_max *res, int v){
    struct min_max l;
    struct min_max r;

    res->min = root->val;
    res->max = root->val;
    
    if(root == NULL){
        res->min = v;
        res->max = v;
        return true;
    }
    
    if ((root->left != NULL && !isBST(root->left, &l, root->val)) 
    || (root->right != NULL && !isBST(root->right, &r, root->val))){
        return false;
    }
    
    if((root->left != NULL && l.max >= root->val)
       || (root->right != NULL && r.min <= root->val))
        return false;
    
    res->min = root->left != NULL? l.min : root->val;
    res->max = root->right != NULL? r.max : root->val;

    return true;
    

}

bool isValidBST(struct TreeNode* root) {
    struct min_max res;
    if(root == NULL) return true;
    return isBST(root, &res, root->val);
}
