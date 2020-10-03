
// @Title: 反转链表 II (Reverse Linked List II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-10 16:09:33
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
    struct ListNode *br = head;
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while(br!=NULL){
        cur = br;
        br = br->next;
        cur->next = pre;
        pre = cur;
    }
    return cur;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n) return head;
    struct ListNode* lohead = (struct ListNode*)malloc(sizeof(struct ListNode));
    lohead->next = head;
    struct ListNode* lo_tail = lohead;
    
    struct ListNode* orhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* br = head;
    struct ListNode* pre = lohead;
    struct ListNode* tail;
    
    struct ListNode* hihead = (struct ListNode*)malloc(sizeof(struct ListNode));

    int sum = 1;
    while(sum<=n){
        if(sum == m){   
            lo_tail = pre;
            pre->next = NULL;
            orhead->next = br;
        }
        if(sum == n){
            hihead->next = br->next;
            br->next = NULL;
            tail = orhead->next;
        }
        sum++;
        pre = br;
        br = br->next;
    }   
    lo_tail->next = reverseList(orhead->next);
    tail->next = hihead->next;
    return lohead->next;
    
}
