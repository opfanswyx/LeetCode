
// @Title: 合并两个有序数组 (Merge Sorted Array)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-26 21:34:44
// @Runtime: 0 ms
// @Memory: N/A

void merge(int* nums1, int m, int* nums2, int n) {
    int k;
    
    k = m + n;
    
    while(n != 0)
        nums1[--k] = m==0 || nums2[n-1] >= nums1[m-1] ? nums2[--n] : nums1[--m];
}
