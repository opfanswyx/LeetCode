
// @Title: 删除链表的倒数第N个节点 (Remove Nth Node From End of List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-25 10:24:32
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#if 0
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
 struct ListNode* tmp1=head;
    struct ListNode* tmp=head;
    struct ListNode* tail=head->next;
    int count=0;
    int size;
    int i=1;
    
    while(tmp1!=NULL)
    {
        count++;
        tmp1=tmp1->next;
    }
    
    
   size=count-n;
   if(count==1) return NULL;
   if(n==1) 
   {
       while(tail->next!=NULL)
       {
           tmp=tmp->next;
           tail=tail->next;
       }
       
       tmp->next=NULL;
       return head;
   }
    while(i<size+1)
    {      
        tmp=tmp->next;
        tail=tail->next;
        i++;
       
    }  

    tmp->val=tail->val;
    tmp->next=tail->next;
    
    return head;
}
#endif
#if 1
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {

    struct ListNode* front = head;
    struct ListNode* behind = head;

    while (front != NULL) {
        front = front->next;

        if (n-- < 0) behind = behind->next;
    }
    if (n == 0) head = head->next;
    else behind->next = behind->next->next;
    return head;
}
#endif
