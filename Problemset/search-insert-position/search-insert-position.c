
// @Title: 搜索插入位置 (Search Insert Position)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-23 23:09:43
// @Runtime: 0 ms
// @Memory: N/A

int searchInsert(int* nums, int numsSize, int target) {
    if(0 == numsSize)
        return 0;
    
    int i = 0;
    
    for(; i < numsSize; i++)
    {
        if(nums[i] >= target)
        {
            return i;
        }
        if(i == numsSize-1)
        {
            return i+1;
        }
    }
    return 0;
}
