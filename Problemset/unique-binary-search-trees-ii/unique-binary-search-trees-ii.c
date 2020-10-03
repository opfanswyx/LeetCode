
// @Title: 不同的二叉搜索树 II (Unique Binary Search Trees II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-12 10:11:16
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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode* push(struct TreeNode*** arr, int* returnSize, int a)
{
    struct TreeNode *t = NULL;
    if(a > -1) //only valid value can be allocated;
    {
        t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        t->left = t->right = NULL;
        t->val = a;
    }
    *returnSize += 1;
    *arr = (struct TreeNode**)realloc(*arr, sizeof(struct TreeNode*)*(*returnSize));
    (*arr)[*returnSize-1] = t;
    return t; //return this node for -> root;
}
struct TreeNode* generate(int begin, int end, int* returnSize)
{
    struct TreeNode** arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    if(begin >= end)
    {
        if(begin > end) 
            push(&arr, returnSize, -1);
        if(begin == end)
            push(&arr, returnSize, begin);
        return arr;
    }
    for(int i = begin; i <= end; i++) //try to set each value as root;
    {
        int count0=0, count1=0;
        struct TreeNode **arr0 = generate(begin, i-1, &count0);
        struct TreeNode **arr1 = generate(i+1, end, &count1);
        for(int j = 0; j < count0; j++) //try to use different node as left and right child;
            for(int k = 0; k < count1; k++)
            {
                struct TreeNode* t = push(&arr, returnSize, i);
                t->left = arr0[j];
                t->right = arr1[k];
            }
    }
    return arr;
}

//AC - 8ms;
struct TreeNode** generateTrees(int n, int* returnSize)
{
    *returnSize = 0;
    if(!n) return NULL;
    return generate(1, n, returnSize);
}
