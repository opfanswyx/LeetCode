
// @Title: 搜索旋转排序数组 II (Search in Rotated Sorted Array II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-07 09:33:08
// @Runtime: 0 ms
// @Memory: N/A

/*similar as problem 11. search in rotated sorted array
 * but add the duplicate case: compare values of left, right, mid, target
 */
bool search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize-1, mid, tmp;
    
    while (left<right) {
        mid = (left+right)/2;
        //printf("pos-1: left:%u, mid:%u, right:%u\n", left, mid, right);
        if(target == nums[mid]) {            
            return true;
        }
        
        if((nums[mid] > nums[left] && target >=nums[left] && target < nums[mid])||
           (nums[left]> nums[right] && nums[mid]< nums[left] && ((target<nums[mid])||(target > nums[right]))) ||
          (nums[left] == nums[right] &&
           ((nums[mid]< nums[left] && (target > nums[left] || target <nums[mid]))||
            (nums[mid]>nums[left] && target < nums[mid] && target >nums[left])))){
            right = mid-1;
            //printf("pos-2.0: left:%u, right:%u\n", left, right);
        } else if (nums[left] == nums[right] && nums[mid] == nums[left]) {
            /*same nums on the left side*/
            tmp = left;
            while(tmp<mid && nums[tmp]==nums[mid]) tmp++;
            if(tmp == mid){
                left = mid + 1;
            }else {
                right = mid -1;
            }
        } else {
            left = mid+1;
            //printf("pos-3:left:%u, right:%u\n", left, right);
        }
    }
    
    if(target == nums[left]) {
        return true;
    }
    return false;
}
#if 0
bool search(int* nums, int numsSize, int target) {
     int l = 0, m;
     numsSize--;
     while (l <= numsSize) {
        m = (l+numsSize) >> 1;
        if (nums[numsSize] == target || nums[m] == target || nums[l] == target) return true;
        if (nums[numsSize] == nums[l]) l++, numsSize--;
        else if (nums[numsSize] > target) {
            if (nums[m] < target || nums[m] > nums[numsSize]) l = m+1;
            else numsSize = m-1;
        } else {
            if (nums[m] > target || nums[m] < nums[numsSize]) numsSize = m-1;
            else l = m+1;
        }
    }
    return false;
}
#endif
