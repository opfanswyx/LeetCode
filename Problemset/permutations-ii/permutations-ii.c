
// @Title: 全排列 II (Permutations II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-29 11:41:18
// @Runtime: 8 ms
// @Memory: N/A

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void permute_step(int* p, int n, int* k, int** rp, int nn)
{
	if (n == 1)
	{
		rp[*k][n - 1] = p[0];
		for (int i = 0;i < nn;i++)
		{
			if (rp[*k][i] <= -1024) rp[*k][i] = rp[(*k) - 1][i];
		}
		(*k)++;
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			if (i != 0 && p[i] == p[i - 1]) continue;
			rp[*k][n - 1] = p[i];
			int* q = (int*)malloc(sizeof(int)*(n-1));
			for (int j = 0;j < n;j++)
			{
				if (j < i) q[j] = p[j];
				if (j > i) q[j - 1] = p[j];
			}
			qsort(q, n - 1, 4, cmp);
			permute_step(q, n - 1, k, rp, nn);
			free(q);
		}
	}
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
	qsort(nums, numsSize, 4, cmp);
	*returnSize = 1;
	int num = 1;
	for (int i = 1;i <= numsSize;i++)
	{
		if (i != 1 && nums[i - 1] == nums[i - 2]) num = num + 1;
		else num = 1;
		*returnSize *= i;
		*returnSize /= num;
	}
	int** r = (int**)malloc(sizeof(int*)*(*returnSize));
	for (int i = 0;i < *returnSize;i++)
	{
		r[i] = (int*)malloc(sizeof(int)*numsSize);
		for (int j = 0;j < numsSize;j++)
			r[i][j] = -1024;
	}
	int k = 0;int* kp = &k;
	permute_step(nums, numsSize, kp, r, numsSize);
	return r;
}
#if 0
//相比I只需要加入排序和“筛选语句”即可
void swap(int *r1,int *r2){
    int temp;
    temp=*r1;
    *r1=*r2;
    *r2=temp;
}
void quickSort(int *nums,int l,int r){
    int i,j;
    if(l<r){
        i=l;
        j=r+1;
        while(1){
            do i++;
            while(!(nums[l]<=nums[i]||i==r));
            do j--;
            while(!(nums[l]>=nums[j]||j==l));
            if(i<j)
                swap(&nums[i],&nums[j]);
            else
                break;
        }
        swap(&nums[l],&nums[j]);
        quickSort(nums,l,j-1);
        quickSort(nums,j+1,r);
    }
}
void DFS(int* nums,int numsSize,bool* flag,int deep,int* nums_record,int** permuted,int* count)
{
    int i;
    if(deep==numsSize)
    {
        permuted[*count]=(int*)malloc(sizeof(int)*(deep));
        for(i=0;i<deep;i++)
        {
            permuted[*count][i]=nums_record[i];
            printf("%d,",nums_record[i]);
        }
        (*count)++;
        printf("\n");
        return;
    }
    for(i=0;i<numsSize;i++)
    {
        if(i>0&&nums[i]==nums[i-1]&&!flag[i-1]) //筛选语句
            continue;
        if(!flag[i])
        {
            //printf("%d#%d,",i,deep);
            flag[i]=true;
            nums_record[deep]=nums[i];  
            DFS(nums,numsSize,flag,deep+1,nums_record,permuted,count);
            flag[i]=false;
        }
    }
    return;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    bool *flag;
    int deep=0,*nums_record,**permuted,i,num=0;
    if(numsSize==0)
        return;
    else if(numsSize==1)
    {
        permuted=(int**)malloc(sizeof(int*));
        permuted[0]=(int*)malloc(sizeof(int));
        permuted[0][0]=nums[0];
        *returnSize=1;
        return permuted;
    }
    quickSort(nums,0,numsSize-1);
    nums_record=(int*)malloc(sizeof(int)*numsSize);
    permuted=(int**)malloc(sizeof(int*)*10000);
    flag=(bool*)malloc(sizeof(bool)*numsSize);
    for(i=0;i<numsSize;i++)
    {
        flag[i]=false;
    }
    *returnSize=0;
    DFS(nums,numsSize,flag,deep,nums_record,permuted,returnSize);
    permuted=(int**)realloc(permuted,sizeof(int*)*(*returnSize));
    return permuted;
}
motification:
1.Sort the nums.
2.In the function DFS, continue when nums[i]==nums[i-1] && flag[i-1]==false.
    #endif
