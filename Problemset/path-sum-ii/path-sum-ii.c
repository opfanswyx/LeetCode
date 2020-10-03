
// @Title: 路径总和 II (Path Sum II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-15 19:04:02
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct TreeNode tn;

int maxDepth(tn* root)
{
  if(root==NULL)        return 0;
  int lDep = maxDepth(root->left);
  int rDep = maxDepth(root->right);
  return (lDep> rDep)?lDep+1:rDep+1;
}

void helper(tn* node, int sum,
            int* cur, int curS,
            int** colS, int* retS, int** ret)
{
  /* term */
  if(node->val == sum &&
     !node->left && !node->right)
  {
    /* got a match */
    ret[*retS] = (int*)malloc(sizeof(int)* (curS+1));
    memcpy(ret[*retS], cur, sizeof(int) * curS);
    ret[*retS][curS] = node->val;
    (*colS)[*retS] = curS +1;
    (*retS)++;
    return;
  }

  cur[curS] = node->val;
  /* dfs */
  if(node->left)
    helper(node->left, sum-cur[curS], cur, curS+1, colS, retS, ret);

  if(node->right)
    helper(node->right, sum-cur[curS], cur, curS+1, colS, retS, ret);    
}

int** pathSum(tn* root, int sum, int** colS, int* retS)
{
  *retS = 0;
  if(root == NULL) return NULL;

  *colS = (int*)malloc(sizeof(int)*500);
  int** ret = (int**)malloc(sizeof(int*)*500);
  
  int cur[maxDepth(root)];
  helper(root, sum, cur, 0, colS, retS, ret);

  return ret;
}
