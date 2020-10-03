
// @Title: 螺旋矩阵 (Spiral Matrix)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-31 09:38:30
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    
    int rStart = 0; //Row start index
    int rEnd = matrixRowSize-1; //Row end  index
        
    int cStart = 0; //Col start index
    int cEnd = matrixColSize-1; //Col end index
    
    int size = matrixRowSize * matrixColSize; //Total size of the return array, use this to track over flow
    int *ret_array = malloc(sizeof(int) * size);
    int widx = 0;
    
    while(rStart <= rEnd && cStart <= cEnd) {
        
        for(int i = cStart; i <= cEnd && widx < size; i++)
            ret_array[widx++] = matrix[rStart][i];
        rStart++; //Done with current top row

        for(int i = rStart; i <= rEnd && widx < size; i++)
            ret_array[widx++] = matrix[i][cEnd];  
        cEnd--; //Done with current right col

        
        for(int i = cEnd; i >= cStart && widx < size; i--)
            ret_array[widx++] = matrix[rEnd][i];
        rEnd--; //Done with current bottom row

        
        for(int i = rEnd; i >= rStart && widx < size; i--)
            ret_array[widx++] = matrix[i][cStart];
        cStart++; //Done with current left col
    }
    
    return ret_array;
    
}
