
// @Title: 组合总和 (Combination Sum)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-29 11:06:07
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void subSUm(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int index, int **sumArr, int curpos, int * sumbuff){
    
    if(target < 0){
         return;      
    }
    else if(0 == target){
        sumArr[*returnSize] = (int *)malloc(curpos*sizeof(int));
        memcpy(sumArr[*returnSize], sumbuff, curpos*sizeof(int));
        (*columnSizes)[*returnSize] = curpos;
        (*returnSize) = (*returnSize) + 1;
        return;
    }
    for(int i = index; i < candidatesSize; i++){
        int subtarget = target - candidates[i];
        sumbuff[curpos] = candidates[i];
        subSUm(candidates, candidatesSize, subtarget, columnSizes, returnSize, i, sumArr, curpos+1, sumbuff);
    }
    
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    
    int **sumArr = (int **)malloc(512*sizeof(int *));
    int *sumbuff = (int *)malloc(512*sizeof(int));
    *columnSizes = (int *)malloc(512*sizeof(int));
    
    *returnSize = 0;
    subSUm(candidates, candidatesSize, target, columnSizes, returnSize, 0, sumArr, 0, sumbuff);
    
    return sumArr;
}
