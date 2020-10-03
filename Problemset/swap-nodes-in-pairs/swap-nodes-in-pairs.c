
// @Title: 两两交换链表中的节点 (Swap Nodes in Pairs)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-25 10:49:18
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    typedef struct ListNode Node;
    Node *root  = head;
    Node *prev = NULL;
    int temp;
    int count = 0;
    while(head != NULL){
        if(count %2 == 1){
            temp = prev->val;
            prev->val = head->val;
            head->val = temp;
        }
        prev = head;
        head = head->next;
        count++;
    }
    return root;
}
