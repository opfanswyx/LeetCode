
// @Title: 删除链表中的节点 (Delete Node in a Linked List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-16 15:26:10
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
        if(node != NULL && node->next != NULL){
        node->val=node->next->val;
        free(node->next);
        node->next=node->next->next;
    }
}
