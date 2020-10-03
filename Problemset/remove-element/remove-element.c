
// @Title: 移除元素 (Remove Element)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-23 00:25:16
// @Runtime: 0 ms
// @Memory: N/A

int removeElement(int* nums, int numsSize, int val) {
    int j, i = 0;
    for(j = 0; j < numsSize; j++){
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
