
// @Title: 合并两个有序链表 (Merge Two Sorted Lists)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-21 23:21:30
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* now = ans;
    do
    {
        if(l1->val < l2->val)
        {
            now->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            now->val = l2->val;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 == NULL)
        {
            now->next = NULL;
            break;
        }
        else
        {
            if(l1 == NULL && l2 != NULL)
            {
                now->next = l2;
                break;
            }
            if(l1 != NULL && l2 == NULL)
            {
                now->next = l1;
                break;
            }
            struct ListNode* new = (struct ListNode *)malloc(sizeof(struct ListNode));
            now->next = new;
            now = new;
        }
    }while(1);
    return ans;
}
