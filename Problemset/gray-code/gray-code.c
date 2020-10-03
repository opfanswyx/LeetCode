
// @Title: 格雷编码 (Gray Code)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-08 10:18:42
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
  
  int size = 1 << n;
  *returnSize = size;
  int* arr = (int*)malloc(sizeof(int)*size);

  memset(arr, 0, sizeof(int)*size);
  
  for(int idx = 0; idx < n; idx++)
  {
    int bracket = 1 << idx;
    int temp = bracket;

    while(bracket)
    {
      arr[temp++] = (1 << idx) | arr[(bracket--) - 1];
    }
  }
  return arr; 
}
