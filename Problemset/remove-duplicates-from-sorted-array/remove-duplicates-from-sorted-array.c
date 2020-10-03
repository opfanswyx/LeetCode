
// @Title: 删除排序数组中的重复项 (Remove Duplicates from Sorted Array)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-23 00:00:49
// @Runtime: 8 ms
// @Memory: N/A

int removeDuplicates(int* nums, int numsSize) {
    if(!numsSize)
    return numsSize;
  int pos = 1, len = 1; 
  for(int i = 1; i < numsSize; i++)
  {
    if(nums[i-1] != nums[i])
    {
      nums[pos] = nums[i]; 
      pos++; ++len;
    }
  }
  return len;
}
