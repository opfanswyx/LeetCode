
// @Title: 两个数组的交集 II (Intersection of Two Arrays II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-22 19:30:54
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare_int( const void* a, const void* b )
{
  if( *(int*)a == *(int*)b ) return 0;
  return *(int*)a < *(int*)b ? -1 : 1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,
               int* returnSize) {
  qsort(nums1, nums1Size, sizeof(int), compare_int);
  qsort(nums2, nums2Size, sizeof(int), compare_int);
  int i = 0, j = 0;
  *returnSize = 0;
  int max = nums1Size > nums2Size ? nums1Size : nums2Size;
  int *res =  malloc(max * sizeof(int));
  while (i < nums1Size && j < nums2Size) {
    if (nums1[i] == nums2[j]) {
      res[(*returnSize)++] = nums1[i];
      ++i;
      ++j;
    } else if (nums1[i] < nums2[j]) ++i;
    else ++j;
  }

  return res;
}
