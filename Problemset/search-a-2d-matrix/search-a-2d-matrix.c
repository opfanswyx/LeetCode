
// @Title: 搜索二维矩阵 (Search a 2D Matrix)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-05 09:53:10
// @Runtime: 4 ms
// @Memory: N/A


bool bsch(int row, int s, int e, int target, int** matrix){
    int mid;
    while(s <= e){
        mid = (e + s)/2;
        
        if(matrix[row][mid] == target){
            return true;
        }
        
        if(matrix[row][mid] < target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int s = 0;
    int mid;
    int e = matrixRowSize;
    if(matrixRowSize > 1){
        while(e - s > 1){
            mid = (s + e)/2;
            if(matrix[mid][0] == target)
                return true;
        
            if(matrix[mid][0] < target){
                s = mid;
            }else{
                e = mid - 1;
            }
        }
    }
    
    if(s != e && e < matrixRowSize){
        return (bsch(s, 0, matrixColSize-1, target, matrix) | bsch(e, 0, matrixColSize-1, target, matrix));
    }
    else{
        return bsch(s, 0, matrixColSize-1, target,  matrix);
    }
}
