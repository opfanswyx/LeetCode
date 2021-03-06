
// @Title: 全排列 (Permutations)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-29 11:35:35
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* p, int* q)
{
    int t = *p; *p = *q; *q = t;
}
void search(int* nums, int size, int*** arr, int* returnSize, int begin, int end)
{
    if(begin == end)
    {
        (*returnSize)++;
        *arr = (int**)realloc(*arr, sizeof(int*)*(*returnSize));
        (*arr)[*returnSize-1] = (int*)malloc(sizeof(int)*size);
        for(int i = 0; i < size; i++)
            (*arr)[*returnSize-1][i] = nums[i];
        return;
    }
    for(int i = begin; i <= end; i++)
    {
        swap(nums+begin, nums+i); //try to use each element as the head;
        search(nums, size, arr, returnSize, begin+1, end);
        swap(nums+begin, nums+i);
    }
}

//AC - 4ms;
int** permute(int* nums, int size, int* returnSize)
{
    *returnSize = 0;
    int** arr = (int**)malloc(sizeof(int*));
    search(nums, size, &arr, returnSize, 0, size-1);
    return arr;
}
