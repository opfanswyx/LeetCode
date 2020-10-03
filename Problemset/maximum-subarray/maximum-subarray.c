
// @Title: 最大子序和 (Maximum Subarray)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-24 11:58:50
// @Runtime: 4 ms
// @Memory: N/A

int maxSubArray(int* nums, int numsSize) {
    if(0 == numsSize)
        return 0;
    int arr[numsSize],max;
    arr[0] = nums[0];
    
    for(int i=1; i<numsSize; i++)
        arr[i] = arr[i-1]+nums[i] > nums[i] ? arr[i-1]+nums[i] : nums[i];
    
    max=arr[0];
    for(int i=1; i<numsSize; i++)
        max = max > arr[i] ? max : arr[i];
    
    return max;
}
