
// @Title: 二叉树的层次遍历 II (Binary Tree Level Order Traversal II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-28 23:10:28
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int maxDepth(struct TreeNode* root){
    if(root==NULL)
        return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return (left>right?left+1:right+1);
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
    if(root==NULL)
        return NULL;
    int depth=*returnSize=maxDepth(root);
    int **result=(int **)malloc(sizeof(int*)*depth);
    *columnSizes=(int *)malloc(sizeof(int)*depth);
    int front=0;
    int rear=0;
    struct TreeNode* queue[10000];
    queue[rear]=root;
    rear++;
    while(front<rear)
    {
        int start=front;
        int end=rear;
        columnSizes[0][--depth]=end-start;
        front=rear;
        result[depth]=(int*)malloc(sizeof(int)*(end-start));
        int i;
        for(i=start;i<end;i++)
        {
            result[depth][i-start]=queue[i]->val;
            if(queue[i]->left!=NULL)
            {
                queue[rear++]=queue[i]->left;
                
            }
            if(queue[i]->right!=NULL)
            {
                queue[rear++]=queue[i]->right;
                
            }
            
        }
    }
    return result;
}
#if 0
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(root==NULL)
        return NULL;
    int depth=*returnSize=maxDepth(root);
    
    int** res=(int**)calloc(depth,sizeof(int*));
    *columnSizes=(int*)calloc(depth,sizeof(int));
    
    
    struct TreeNode* queue[5000];
    int front=0,rear=0;
    queue[rear++]=root;
    int cur_size=1;
    int next_size=0;
    int size=depth-1;
    
    while(front<rear){
        res[size]=(int *)malloc(2000*sizeof(int));
        
        for(int i=0;i<cur_size&&front<rear;i++){
            struct TreeNode* temp=queue[front++];
            res[size][i]=temp->val;
            
            if(temp->left){
                queue[rear++]=temp->left;
                next_size++;
            }
            
            if(temp->right){
                queue[rear++]=temp->right;
                next_size++;
            }
        }
        
        (*columnSizes)[size--]=cur_size; //指向数组的指针
        
        cur_size=next_size;
        if(cur_size==0)
            break;
        next_size=0;
    }
    return res;
}
#endif
