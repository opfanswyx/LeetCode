
// @Title: 回文链表 (Palindrome Linked List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-15 18:00:20
// @Runtime: 8 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void MidNode(struct ListNode *head, struct ListNode **mid)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    *mid = slow;
}

void ReverseList(struct ListNode *old, struct ListNode **new)
{
    struct ListNode *prev=NULL, *cur=old, *next=old;
    while (cur)
    {
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *new = prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    
    struct ListNode *mid, *head2;
    MidNode(head, &mid);
    ReverseList(mid, &head2);
    
    while (head && head2)
    {
        if (head->val != head2->val)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
