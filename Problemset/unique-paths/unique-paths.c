
// @Title: 不同路径 (Unique Paths)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-02 15:10:48
// @Runtime: 0 ms
// @Memory: N/A

/**
The problem is equal to 
'go from bottom right corner to the top left corner.can only move either up or left.'

1, 1, 1, 1
1, 2, 3, 4  <---- the number is the possible unique ways of the grid. 
1, 3, 6,10   
1, 4,10,20

Compare the line 1 and line 2
1,1,1,1 --> 1,1+1,2+1,3+1 --> 1,2,3,4

Compare the line 2 and line 3
1,2,3,4 --> 1,2+1,3+3,4+6 --> 1,3,6,10

Compare the line 3 and line 4
1,3,6,10 --> 1,3+1,6+4,10+10 --> 1,4,10,20

Thus,for a initial array [1,1,1,1].
Generate the new element by using x[i] = x[i] + x[i-1] .
For example.
int A[4] = {1};
A[2] += A[1]; 1+1
A[3] += A[2]; 1+2
A[4] += A[3]; 1+3
then A is [1,2,3,4], with new generation just repeat the steps above.
The time complex is O(mn). Space complex is O(n).
**/
int uniquePaths(int m, int n) {
    int *x = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;++i)
        x[i] = 1;
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            x[j] += x[j-1];
        }
    }
    return x[n-1];
}
#if 0
int uniquePaths(int m, int n) {
    int **grid;
    int i, j, leftIdx, topIdx, result;
    
    grid = (int **)malloc(m * sizeof(int *));
    
    for (i = 0; i < m; i++) {
        grid[i] = (int *)calloc(n, sizeof(int));
    }
    
    grid[0][0] = 1;
    for (i = 0; i < m; i ++) {
        for (j = 0; j < n; j++) {
            // check left
            leftIdx = i - 1;
            if (leftIdx >= 0) {
                grid[i][j] += grid[leftIdx][j];
            }
            
            // check top
            topIdx = j - 1;
            if (topIdx >= 0) {
                grid[i][j] += grid[i][topIdx];
            }
        }
    }
    
    result = grid[m-1][n-1];
    
    for (i = 0; i < m; i++) {
        free(grid[i]);
        grid[i] = NULL;
    }
    
    free(grid);
    grid = NULL;
    
    return result;
}
#endif
