
// @Title: 三角形最小路径和 (Triangle)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 11:26:39
// @Runtime: 0 ms
// @Memory: N/A

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int i, j;
    int mins = INT_MAX;
    
    for (i = 1; i < triangleRowSize; i++) {
        /* edge case */
        triangle[i][0] = triangle[i - 1][0] + triangle[i][0];

        for (j = 1; j < triangleColSizes[i] - 1; j++) {
            triangle[i][j] = MIN(triangle[i - 1][j - 1] + triangle[i][j], triangle[i - 1][j] + triangle[i][j]);
                
            /* track min value between the edge cases */
            if (i == triangleRowSize - 1)
                mins = MIN(mins, triangle[i][j]);
        }
        /* edge case */
        triangle[i][j] = triangle[i - 1][triangleColSizes[i - 1] - 1] + triangle[i][j];
    }
    
    /* final min including the edge cases */
    mins = MIN(mins, MIN(triangle[triangleRowSize - 1][0], triangle[triangleRowSize - 1][triangleColSizes[triangleRowSize - 1] - 1]));
    
    return mins;
}
