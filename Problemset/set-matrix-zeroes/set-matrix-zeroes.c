
// @Title: 矩阵置零 (Set Matrix Zeroes)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-05 09:47:40
// @Runtime: 12 ms
// @Memory: N/A

void setZeroes(int** matrix, int rSize, int cSize)
{
    int col0 = 1; //the first column can be affected by the other columes of the first row;
    for(int r = 0; r < rSize; r++)
    {
        if(matrix[r][0]==0) col0 = 0;
        for(int c = 1;  c < cSize; c++)
            if(matrix[r][c]==0)
                matrix[r][0] = matrix[0][c] = 0;
    }
    for(int r = rSize-1; r > -1; r--) //using reverse direction to ensure previously set value will not affect the latter ones;
    {
        for(int c = cSize-1; c > 0; c--)
            if(matrix[r][0]==0 || matrix[0][c]==0)
                matrix[r][c] = 0;
        if(col0==0) matrix[r][0] = 0; //ensure the first column will not affect the other columns in the same row;
    }
}
#if 0
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int delRowOne = 0; // aux var
    
    // scan row 1 for zeros
    for (int rowOneScan = 0; rowOneScan < matrixColSize; rowOneScan++) {
        if (matrix[0][rowOneScan] == 0) {
            delRowOne = 1;
            break;
        }
    }
    
    // zero out rows from bottom to top, storing column deletion mark '0' in row 0
    for (int row = matrixRowSize-1; row > 0; row--) { // skip 0th row
        int clearRow = 0; // aux var
        for (int col = matrixColSize-1; col > -1; col--) { // hit 0th col
            if (matrix[row][col] == 0) {
                matrix[0][col] = 0;
                clearRow = 1;
            }
        }
        for (int col = matrixColSize-1; col > -1; col--) {
            if (clearRow) {
                matrix[row][col] = 0;
            }
        }
    }
    
    // scan row 1 and delete columns based on 0's
    for (int col = 0; col < matrixColSize; col++) {
        if (matrix[0][col] == 0) {
            for (int row = 0; row < matrixRowSize; row++) {
                matrix[row][col] = 0;
            }
        }
        if (delRowOne) {
            matrix[0][col] = 0;
        }
    }
}
#endif
