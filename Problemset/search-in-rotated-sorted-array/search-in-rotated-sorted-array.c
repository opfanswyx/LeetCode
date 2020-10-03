
// @Title: 搜索旋转排序数组 (Search in Rotated Sorted Array)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-26 11:45:09
// @Runtime: 4 ms
// @Memory: N/A

int search(int* nums, int numsSize, int target) {
    int i=0;
    int j=numsSize-1;
    int result=-1;
    while(i<=j){
        if(nums[i]==target)
            return i;
        if(nums[j]==target)
            return j;
        if(nums[i]!=target)
            i++;
        if(nums[j]!=target)
            j--;
    }
    return result;
}
