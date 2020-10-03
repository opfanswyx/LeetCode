
// @Title: 合并K个升序链表 (Merge k Sorted Lists)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 14:14:05
// @Runtime: 12 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *divide_and_conquer(struct List **res,int left,int right)
{
    if(right==left)
    {
        //res[1]=NULL;
        return res[left];
    }

    struct ListNode *tempLeft,*tempRight;

    int center=(right+left)/2;
    tempLeft=divide_and_conquer(res,left,center);     //divide querstion to smaller question
    tempRight=divide_and_conquer(res,center+1,right);

    if(tempLeft==NULL&&tempRight==NULL)
    {
        return NULL;
    }

    struct ListNode *free_left=tempLeft;                          //aim to free the last linked list
    struct ListNode *free_right=tempRight;

    struct ListNode *tempRes=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pTail=tempRes;

    while(tempLeft!=NULL||tempRight!=NULL)  //similar with merge two linked list 
    {
        struct ListNode *pNew=(struct ListNode *)malloc(sizeof(struct ListNode));
        if(tempLeft!=NULL&&tempRight!=NULL)
        {
            if(tempLeft->val>=tempRight->val)
            {
                pNew->val=tempRight->val;
                tempRight=tempRight->next;
            }
            else
            {
                pNew->val=tempLeft->val;
                tempLeft=tempLeft->next;
            }
            //pTail->next=pNew;
            //pNew->next=NULL;
            //pTail=pNew;
        }
        else if(tempLeft==NULL)
        {
            //int a=0;
            pNew->val=tempRight->val;
            //pTail->next=pNew;
            //pNew->next=NULL;
            //pTail=pNew;
            tempRight=tempRight->next;
        }
        else if(tempRight==NULL)
        {
            pNew->val=tempLeft->val;
            //pTail->next=pNew;
            //pNew->next=NULL;
            //pTail=pNew;
            tempLeft=tempLeft->next;
        }
        pTail->next=pNew;
        pNew->next=NULL;
        pTail=pNew;
    }
    if(free_left!=NULL)
    {
        free(free_left->next);
    }
    if(free_right!=NULL)
    {
        free(free_right->next);
    }
    return tempRes->next;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (lists==NULL||listsSize==0)
    {
        return NULL;
    }
    //struct ListNode **ans=malloc()
    return divide_and_conquer(lists,0,listsSize-1);
}
