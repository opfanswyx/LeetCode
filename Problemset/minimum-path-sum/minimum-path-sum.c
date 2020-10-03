
// @Title: 最小路径和 (Minimum Path Sum)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-03 09:51:27
// @Runtime: 4 ms
// @Memory: N/A

int min(int x, int y)
{
    return x < y ? x : y;    
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int solnMatrix[gridRowSize][gridColSize];
    int i, j;
    
    solnMatrix[0][0] = grid[0][0];
    for (i = 1; i < gridColSize; i++)
        solnMatrix[0][i] = grid[0][i] + solnMatrix[0][i-1];
    
    for (i = 1; i < gridRowSize; i++)
        solnMatrix[i][0] = grid[i][0] + solnMatrix[i-1][0];
    
    for (i = 1; i < gridRowSize; i++)
        for (j = 1; j < gridColSize; j++)
            solnMatrix[i][j] = grid[i][j] + min (solnMatrix[i-1][j], solnMatrix[i][j-1]);
    
    return solnMatrix[gridRowSize - 1][gridColSize - 1];
}
