
// @Title: 只出现一次的数字 (Single Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-10 22:55:28
// @Runtime: 4 ms
// @Memory: N/A

int singleNumber(int* nums, int numsSize) {
    int n = 0;
    for (int i = 0; i < numsSize; i++){
        n ^= nums[i];
    }
    return n;
}
