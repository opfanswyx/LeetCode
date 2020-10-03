
// @Title: 旋转数组 (Rotate Array)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 11:00:48
// @Runtime: 4 ms
// @Memory: N/A

void rotate(int* nums, int numsSize, int k) {
    int i;
    if(k>numsSize)
        k -= numsSize;
    int *data = (int *)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
    {
        data[i]=nums[numsSize-1-i];
    }
    for(i=0;i<numsSize-k;i++)
    {
        nums[numsSize-1-i]=nums[numsSize-k-1-i];
    }
    for(i=0;i<k;i++)
    {
        nums[k-1-i]=data[i];   
    }
}
