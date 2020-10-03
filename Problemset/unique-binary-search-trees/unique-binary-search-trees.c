
// @Title: 不同的二叉搜索树 (Unique Binary Search Trees)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-12 10:14:31
// @Runtime: 0 ms
// @Memory: N/A

int numTrees(int n){
    if(n==0)
    return 0;
    int R[n+1];
    R[0] = 0;
    R[1] = 1;
    int i,j;
    for(i = 2; i <= n; i++)
    {
        R[i]=2*R[i-1];
        for(j = 2; j < i; j++)
            R[i]+=R[j-1]*R[i-j];
    }
    return R[n];
}

#if 0
int numTrees(int n) {
    long C = 1;
    for(int i = 0; i < n; ++i) {
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int) C;
}
#endif
