
// @Title: 两个数组的交集 (Intersection of Two Arrays)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-21 16:30:59
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int max = INT_MIN;
    int len = 0;
    
    for(int i=0;i<nums1Size;i++)
        max = max>nums1[i]?max:nums1[i];
    int* rec = (int*)malloc(sizeof(int)*(max+1));
    for(int i=0;i<=max;i++)
        rec[i]=0;
    
    for(int i=0;i<nums1Size;i++){
        for(int j=0;j<nums2Size;j++){
            if(nums1[i]==nums2[j] && rec[nums1[i]]==0){
                rec[nums1[i]]++;
            }
        }
    }
    
    for(int i=0;i<=max;i++){
        if(rec[i]!=0)
            len++;
    }
    *returnSize = len;
    
    int* res = (int*)malloc(sizeof(int)*len);
    for(int i=0,j=0;i<=max&&j<len;i++){
        if(rec[i]!=0){
            res[j++]=i;
        }
            
    }
    
    return res;
}
