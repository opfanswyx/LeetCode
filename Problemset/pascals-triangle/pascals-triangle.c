
// @Title: 杨辉三角 (Pascal's Triangle)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-09 22:12:13
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int** returnArray = (int**)malloc(sizeof(int*)*numRows);
    *columnSizes = (int*)malloc(sizeof(int)*numRows);
    for(int i=0;i<numRows;i++){
        (*columnSizes)[i] = i+1;
        returnArray[i] = (int*)malloc(sizeof(int)*(i+1));
        returnArray[i][0] = 1;
        returnArray[i][i] = 1;
        for(int j=1;j<i;j++){
            returnArray[i][j] = returnArray[i-1][j] + returnArray[i-1][j-1];
        }
    }
    return returnArray;
}
