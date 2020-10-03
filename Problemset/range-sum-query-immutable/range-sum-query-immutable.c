
// @Title: 区域和检索 - 数组不可变 (Range Sum Query - Immutable)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-19 17:12:45
// @Runtime: 88 ms
// @Memory: N/A

typedef struct NumArray{
    int size;
    int* sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    struct NumArray *array;
    int i;
    
    array = malloc(sizeof(struct NumArray));
    array->sum = malloc((numsSize + 1) * sizeof(int));
    array->size = numsSize;
    array->sum[0] = 0;
    for (i = 0; i < numsSize; i++) {
        array->sum[i+1] = array->sum[i] + nums[i];
    }
    return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return obj->sum[j+1] - obj->sum[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
