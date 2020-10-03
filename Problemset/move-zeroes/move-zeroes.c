
// @Title: 移动零 (Move Zeroes)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-18 15:13:20
// @Runtime: 4 ms
// @Memory: N/A

void moveZeroes(int* nums, int numsSize) {
    int count = 0, c = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
            ++count;
    }
    for(int i = 0; i < numsSize && c < count; i++)
    {
        if(nums[i] != 0)
        {
            nums[c] = nums[i];
            c++;
        }
    }
    for(int i = count; i < numsSize; i++)
        nums[i] = 0;
}
