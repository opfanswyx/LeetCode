
// @Title: 杨辉三角 II (Pascal's Triangle II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-09 22:40:44
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *result = malloc((rowIndex + 1) * sizeof(int));
    int i, j, new, old = 1;
    
    *returnSize = rowIndex + 1;
    
    for (i = 0; i <= rowIndex; i++) {
        result[i] = 1;
        for (j = 1; j < i; j++) {
            new = result[j];
            result[j] += old;
            old = new;
        }
    }
    
    return result;
}
