
// @Title: 螺旋矩阵 II (Spiral Matrix II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-01 10:12:33
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int length = n;
    int loop = 0;
    int num = 1;
    int** m = malloc( n * sizeof(int*) );
    for( int i = 0; i < n; i++ )
        m[i] = malloc( n * sizeof(int) );
    
    while( length > 0 )
    {
        //across the top
        for( int i = 0; i < length; i++ )
            m[loop][loop + i] = num++;
        if( length )
            length--;
        
        //down the right
        for( int i = 0; i < length; i++ )
            m[loop + 1 + i][n - 1 - loop] = num++;
        
        //across the bottom
        for( int i = 0; i < length; i++ )
            m[n - 1 - loop][n - 2 - loop - i] = num++;
        if( length )
            length--;
        
        //up the left
        for( int i = 0; i < length; i++ )
            m[n - 2 - loop - i][loop] = num++;
        
        //loop complete
        loop++;
    }
    
    return m;
}
