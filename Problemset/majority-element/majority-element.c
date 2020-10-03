
// @Title: 多数元素 (Majority Element)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-11 20:42:16
// @Runtime: 4 ms
// @Memory: N/A

int majorityElement(int* nums, int numsSize) {
    int cnt = 0, res;
    for (int i = 0; i < numsSize; ++i) {
        if (cnt == 0) res = nums[i];
        if (res == nums[i]) ++cnt;
        else --cnt;
    }
    return res;
}
