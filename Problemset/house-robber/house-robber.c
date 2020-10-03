
// @Title: 打家劫舍 (House Robber)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 11:48:22
// @Runtime: 0 ms
// @Memory: N/A

int rob(int* nums, int numsSize) {
    if(numsSize==0)
        return 0;
    if(numsSize==1)
        return nums[0];
    
    int *dp=(int*)malloc(sizeof(int)*numsSize);
    dp[0]=nums[0];
    dp[1]=nums[0]>nums[1]?nums[0]:nums[1];
    for(int i=2;i<numsSize;i++)
    {
        dp[i]=dp[i-2]+nums[i]>dp[i-1]?dp[i-2]+nums[i]:dp[i-1];
    }
    return dp[numsSize-1];
}
