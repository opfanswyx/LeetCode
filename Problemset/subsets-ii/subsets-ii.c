
// @Title: 子集 II (Subsets II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-09 11:10:34
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void subSets(int* n, int nS, int pos,
             int k, int subS, int* cur,
             int* colS, int* retS,
             int** ret)
{
  //the # of items in this subset is reached; push current list to the return list
  if(k == subS)
  {
    colS[*retS] = subS;
    if(subS > 0) memcpy(ret[*retS], cur, sizeof(int) * subS);
    (*retS)++;
  }

  //loop through the remaining in nums set
  for(int i = pos; i<nS; i++)
  {
    // skip the duplicate items
    if(i!=pos && n[i] == n[i-1])  continue;

    cur[k] = n[i];
    subSets(n, nS, i+1, k+1, subS, cur, colS, retS, ret);
  }
}

int** subsetsWithDup(int* n, int nS, int** colS, int* retS)
{
  if(nS == 0 || n==NULL)  return NULL;

  int worstCaseLen = pow(2,nS); // worst case no dup so 2^n
  int* cur = (int*)malloc(sizeof(int)*nS);
  int** ret = (int**)malloc(sizeof(int*)* worstCaseLen);  

  for(int i = 0; i<worstCaseLen; i++)
    ret[i] = (int*)malloc(sizeof(int)*nS);
  *retS = 0;
  *colS = (int*)malloc(sizeof(int) * worstCaseLen); 

  //sort first
  qsort(n, nS, sizeof(int), compare);
   
  // the length of subsets varies from 0, 1, ... , n-1, n
  // always start from index 0
  for(int i = 0; i <= nS; i++)
    subSets(n, nS, 0, 0, i, cur, *colS, retS, ret);
  
  return ret;
}
#if 0
#define MAX 12

int set[MAX];
int result_size[1<<MAX];
int temp_result[1<<MAX][MAX];
int count;
int **result;

void xmemcpy(int *dst, int *src, int n)
{
    while(n--)
        *dst++ = *src++;
}

void sort(int *a, int n)
{
    int i;
    int j;
    int t;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void helper(int *a, int start, int index, int N, int K)
{
    int i;
   
    if(K == 0 || start == N)
    {
        xmemcpy(temp_result[count], set, index);
        result_size[count] = index;
        count++;
        return;
    }
    
    set[index] = a[start];
    helper(a, start+1, index+1, N, K-1);
    while(start < N-1 && a[start] == a[start+1])
        start++;
    helper(a, start+1, index, N, K-1);
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int i;
    count = 0;
    sort(nums, numsSize);
    helper(nums, 0, 0, numsSize, numsSize);
    *returnSize = count;
    *columnSizes = (int*) malloc(sizeof(int)*count);
    if(*columnSizes == NULL)
        exit(1);
    xmemcpy(*columnSizes, result_size, count);
    result = (int**)malloc(sizeof(int*)*count);
    if(!result)
        exit(1);
    for(i=0; i<count; i++)
    {
        result[i] = (int*) malloc(sizeof(int)*result_size[i]);
        if(!result[i])
            exit(1);
        xmemcpy(result[i], temp_result[i], result_size[i]);
    }
    return result;
}
#endif
#if 0
struct Node{
    int val;
    struct Node* next;
};

typedef struct Node list_t;

struct List{
    list_t** listlist;
    int size;
};

typedef struct List listlist_t;

list_t* pushnode(list_t* head, int val){
    
    list_t* newNode = (list_t *)malloc(sizeof(list_t));
    list_t* trav = head;
    
    newNode->val = val;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        return head;
    }
    
    trav = head;
    while(trav->next){
        trav = trav->next;
    }
    
    trav->next = newNode;
    
    return head;
}

list_t* popnode(list_t* head){
    
    list_t* toDel = NULL;
    list_t** indirect = &head; 
    
    if(head == NULL){
        return NULL;
    }
    
    while((*indirect)->next){
        indirect = &(*indirect)->next;
    }
    
    toDel = *indirect;
    (*indirect) = (*indirect)->next;
    free(toDel);
    
    return head;
}

void pushback(listlist_t* listArr, list_t* temp){

    list_t* newNode = NULL;
    list_t* trav = temp;
    const int size = listArr->size;
    
    listArr->listlist = (list_t **)realloc(listArr->listlist, sizeof(list_t *) * (size + 1));
    listArr->listlist[size] = NULL;
    
    while(trav){
        listArr->listlist[size] = pushnode(listArr->listlist[size], trav->val);
        trav = trav->next;
    }
    
    trav = temp;
    
    listArr->size = listArr->size + 1;
}

void permute(int *nums, int numsSize, listlist_t *pResult, list_t* temp, int begin){
    
    pushback(pResult, temp);
    
    for(int i = begin; i < numsSize; i++){
        if(i > begin && nums[i] == nums[i - 1]) continue;
        temp = pushnode(temp, nums[i]);
        permute(nums, numsSize, pResult, temp, i + 1);
        temp = popnode(temp);
    }
}

int getListSize(list_t* head){
    
    list_t* trav = head;
    int size = 0;
    
    while(trav){
        trav = trav->next;
        size++;
    }
    
    return size;
}

void copyList(int** ppArr, list_t* head){
    
    int size = getListSize(head);
    int i = 0;
    list_t* trav = head;
    
    *ppArr = NULL;
    
    if(size != 0){
        *ppArr = (int *)malloc(sizeof(int) * size);
        while(trav){
            (*ppArr)[i] = trav->val;
            trav = trav->next;
            i++;
        }
    }
    
    return;
}

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    
    listlist_t result;
    list_t* temp = NULL;
    int row;
    int col;
    int** resultArr = NULL;
    int begin = 0;
    
    result.listlist = NULL;
    result.size = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    permute(nums, numsSize, &result, temp, begin);
    
    row = 0;
    col = 0;
    *returnSize = result.size;
    resultArr = (int **)malloc(sizeof(int *) * result.size);
    *columnSizes = (int *)malloc(sizeof(int) * result.size);
    
    for(row = 0; row < result.size; row++){
        
        (*columnSizes)[row] = getListSize(result.listlist[row]);
        copyList(&resultArr[row], result.listlist[row]); 
    }
    
    return resultArr;
}
#endif
