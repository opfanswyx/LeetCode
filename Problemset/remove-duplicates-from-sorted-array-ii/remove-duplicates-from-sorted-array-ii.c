
// @Title: 删除排序数组中的重复项 II (Remove Duplicates from Sorted Array II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-06 10:51:33
// @Runtime: 4 ms
// @Memory: N/A

/**********************************
Solution: move element ahead in below two cases:

nums[i] != nums[i - 1]

nums[i] == nums[i - 1] && nums[i] != nums[base - 2]

base is the position for next different element moved in.
******************************/

int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0)
        return 0;
        
    int i = 1, index = 1;
    
    for (i = 1; i < numsSize; i++) {
        if ((nums[i] != nums[i - 1]) || i == 1 || (nums[index - 2] != nums[i])) {
                nums[index++] = nums[i];
        }
    }
    
    return index;
}
#if 0
int removeDuplicates(int* nums, int numsSize) {
    int left = 0, right = 1, dup_found = 0;
    
    if (!nums || (numsSize <= 1)) {
        return numsSize;
    }
    while(right < numsSize) {
        if (nums[right] != nums[left]) {
            if ((nums[left+1] == nums[left]) && !dup_found && ((right - left) > 2)) {
                left++;
                dup_found = 1;
            } else {
                dup_found = 0;
            }
            nums[left+1] = nums[right];
            left++;
        } else {
            if (!dup_found) {
                nums[left+1] = nums[right];
                left++;
                dup_found = 1;
            }
        }
        right++;
    }
    return left+1;
}
#endif
