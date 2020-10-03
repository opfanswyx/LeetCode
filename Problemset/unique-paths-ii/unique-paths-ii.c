
// @Title: 不同路径 II (Unique Paths II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-03 09:47:21
// @Runtime: 0 ms
// @Memory: N/A

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int i, j;
    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    for(i = 1; i <= obstacleGridRowSize; i++){
        for(j = 1; j <= obstacleGridColSize; j++){
            if(obstacleGrid[i - 1][j - 1] != 1 && i == 1 && j == 1){
                dp[i][j] = 1;

            }else if(obstacleGrid[i - 1][j - 1] != 1){
                dp[i][j] = dp[i - 1][j] +  dp[i][j - 1];
            }
        }
    }
    return dp[obstacleGridRowSize][obstacleGridColSize]; 
}
