
// @Title: 最接近的三数之和 (3Sum Closest)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-24 09:54:14
// @Runtime: 4 ms
// @Memory: N/A

int comparator(const void *a, const void *b){
    int l = *(const int *)a;
    int r = *(const int *)b;
    return l-r;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort((void *)nums, numsSize, sizeof(nums[0]), comparator);
    int res = 0, flag = 0;;
    for(int i=0;i<numsSize;i++){
        int start = i+1;
        int end = numsSize-1;
        int sum = 0;
        while(start<end){
            sum = nums[i]+nums[start]+nums[end];
            if(flag==1)
                res = (abs(sum-target))<(abs(res-target))?sum:res;
            else
                res = sum;
            
            flag=1;
            
            if((sum-target)<0)
                start++;
            else if((sum-target)>0)
                end--;
            else
                return res;
        }
    }
    return res;
}
#if 0
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, start, end, res, result;
    int sum_c = INT_MAX;
    qsort(nums, numsSize, sizeof(int), cmpfunc); //sort for easy computation
    for(i = 0; i < numsSize; i++){
        for(k = i+1; k < numsSize; k++){
            for(j = k+1; j < numsSize; j++){
                res = nums[i] + nums[j] + nums[k];
                //printf("res %d\n", res);
                if((abs(res - target)) < sum_c){
                    sum_c = abs(res - target);
                    //printf("sum_C %d\n", sum_c);
                    result = res;
                }
            }
        }
    }
    return result;
}
#endif
