
// @Title: 缺失数字 (Missing Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-18 12:00:34
// @Runtime: 4 ms
// @Memory: N/A

int missingNumber(int* nums, int numsSize) {
    int i=0;
    int sum=0;
    for(i=1;i<=numsSize;i++)
        sum+=i;
    for(i=0;i<numsSize;i++)
        sum-=nums[i];
    return sum;
}
