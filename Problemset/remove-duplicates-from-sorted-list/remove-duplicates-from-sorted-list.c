
// @Title: 删除排序链表中的重复元素 (Remove Duplicates from Sorted List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-26 21:12:20
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    if(head==NULL)
        return head;
    
    struct ListNode *now;
    struct ListNode *pre;
    
    now=head->next;
    pre=head;
    while(now!=NULL)
    {
        if(pre->val==now->val)
        {
            pre->next=now->next;
            free(now);
            now=pre->next;
        }
        else
        {
            pre=now;
            now=now->next;
        }
        
    }
    return head;
}
