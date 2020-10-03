
// @Title: 反转链表 (Reverse Linked List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-13 15:41:34
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
   struct ListNode *prev = NULL, *curr = head, *next = NULL;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return (prev);
}
#if 0
struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !(head->next))
        return head;
    struct ListNode* tmp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}
#endif
#if 0
struct ListNode* reverseList(struct ListNode* head) {
    int len=0;
    struct ListNode* p = head;
    while(p!=NULL){
        len++;
        p = p->next;
    }
    int *nums = (int*)malloc(sizeof(int)*len);
    p = head;
    for(int i=0;i<len;i++){
        nums[i] = p->val;
        p = p->next;
    }
    p = head;
    for(int i=len-1;i>=0;i--){
        p->val = nums[i];
        p = p->next;
    }
    return head;
}
#endif
