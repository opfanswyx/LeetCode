
// @Title: 跳跃游戏 (Jump Game)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-31 09:57:10
// @Runtime: 4 ms
// @Memory: N/A

bool canJump(int* nums, int numsSize) {
    int i = 0;
    
    for (int max = 0; i < numsSize && i <= max; i++) {
        max = i + nums[i] > max ? i + nums[i] : max;
    }
    
    return i == numsSize;
}
#if 0
bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) return true;
    int maxIndex = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] + i > maxIndex && maxIndex >= i) {
            maxIndex = nums[i] + i; 
        }
        if (maxIndex >= numsSize - 1) {
            return true;
        }
    }
    return false;
}
# endif
