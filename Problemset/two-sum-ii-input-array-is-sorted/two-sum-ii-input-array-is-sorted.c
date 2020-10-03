
// @Title: 两数之和 II - 输入有序数组 (Two Sum II - Input array is sorted)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-11 19:55:29
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    int* ret = malloc(sizeof(int)*2);
    *returnSize = 2;
    
    int low = 0, high = numbersSize - 1;
    while (low < high) {
        int sum = numbers[low] + numbers[high];
        if (sum == target) {
            ret[0] = low+1;
            ret[1] = high+1;
            return ret;
        } else if (sum < target) {
            low++;
        } else {
            high--;
        }
    }
    exit(1);
}
#if 0
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *p = (int*)malloc(2*sizeof(int));
    int i,j;
    int res=0;
    
    *returnSize=2;
    
    for(i=0;i<numbersSize-1;i++)
    {
        for(j=i+1;j<numbersSize;j++)
        {
            if(numbers[i]+numbers[j] == target)
            {
                    p[0]=i+1;
                    p[1]=j+1;
                    return p;
            }
        }
    }
    return NULL;
}
#endif
