
// @Title: 在排序数组中查找元素的第一个和最后一个位置 (Find First and Last Position of Element in Sorted Array)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-26 12:55:58
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* start = NULL, *end = NULL;
    *returnSize = 2;
    start = nums, end = nums + numsSize - 1;
    int* result = (int *)malloc(sizeof(int)*(*returnSize));
    result[0] = -1, result[1] = -1;
    while (start <= end) {
        if(*start != target)    start++;
        else result[0] = start - nums;
        if(*end != target) end--;
        else result[1] = end - nums;        
        if(result[0] != -1 && result[1] != -1) break;
    }
    return result;
}
#if 0 //false
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    
    int *res=(int *)malloc(sizeof(int)*2);
    res[0]=-1;
    res[1]=-1;
    if(numsSize<2||target==0||nums==NULL)
        return res;
   // if(nu)
    *returnSize=2;
    int flag=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            if(flag==0)
            {
                res[0]=i;
                flag=1;
            }
            else
                res[1]=i;
        }
    }
    if(res[0]==res[1])
    {
        res[0]=res[1]=-1;
    }
    return res;
}
#endif
