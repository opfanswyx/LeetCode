
// @Title: 将有序数组转换为二叉搜索树 (Convert Sorted Array to Binary Search Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-07 21:30:42
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
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    
    int mid = numsSize / 2;
    struct TreeNode* res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    res->val = nums[mid];
    res->left = sortedArrayToBST(nums, mid);
    res->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
    
    return res;
}
