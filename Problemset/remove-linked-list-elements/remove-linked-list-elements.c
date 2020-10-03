
// @Title: 移除链表元素 (Remove Linked List Elements)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 15:59:55
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* cur=head;
    struct ListNode* pre=NULL;

    if(head==NULL)
        return NULL;
    while(cur)
    {
        if(cur->val==val)
        {
            if(pre)
                pre->next=cur->next;
            else
                head=head->next;
        }
        else
        {
            pre=cur;
        }
        cur=cur->next;
    }
    return head;
}
