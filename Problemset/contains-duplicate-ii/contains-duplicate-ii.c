
// @Title: 存在重复元素 II (Contains Duplicate II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-13 17:33:02
// @Runtime: 1164 ms
// @Memory: N/A

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {

    int i,j;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<(numsSize<i+1+k?numsSize:i+1+k);j++)
        {
            if(nums[i]==nums[j])
                return true;
        }
    }
    return false;
}
//numsSize<i+k?numsSize:i+k
