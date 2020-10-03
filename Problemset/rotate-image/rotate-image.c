
// @Title: 旋转图像 (Rotate Image)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-30 11:27:36
// @Runtime: 0 ms
// @Memory: N/A

//相关性质可用三角形全等证明
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int h,l,temp,i,j;
    h=matrixRowSize;
    l=matrixColSizes[0];
    printf("h,l:%d,%d\n",h,l);
    if(l!=h)
        printf("error");
    for(i=0;i<h-1;i++)  //关于次对角线对阵，对角线上元素不用管
    {
        for(j=0;j<l-i-1;j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[l-1-j][l-1-i];
            matrix[l-1-j][l-1-i]=temp;
        }
    }
    for(i=0;i<=(h-1)/2;i++)  //关于横中位线对称
    {
        for(j=0;j<l;j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[h-1-i][j];
            matrix[h-1-i][j]=temp;
        }
    }
    return;
}
