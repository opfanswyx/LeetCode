
// @Title: 环形链表 (Linked List Cycle)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-10 23:17:05
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head||!head->next) 
        return false;
    
    struct ListNode * p1,*p2;
    p1=p2=head;
    
    while(p1&&p2)
    {
        if(p1->next==NULL) 
            return false;
        else 
            p1=p1->next->next;
        
        p2=p2->next;
        if(p1==p2) 
            return true;
    }
    return false;
}
