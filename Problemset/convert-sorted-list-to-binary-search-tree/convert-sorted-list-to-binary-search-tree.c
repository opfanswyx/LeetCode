
// @Title: 有序链表转换二叉搜索树 (Convert Sorted List to Binary Search Tree)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-15 18:51:18
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBSTUtil(struct ListNode *head, struct ListNode *tail) {
    if (head == tail)
        return NULL;
    struct ListNode *mid = head;
    struct ListNode *temp = head;
    //find the mid element
    while (temp!= tail && temp->next != tail) {
        mid = mid->next;
        temp = temp->next->next;
    }
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = sortedListToBSTUtil(head, mid);
    root->right = sortedListToBSTUtil(mid->next, tail);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head)
        return NULL;
    
    return sortedListToBSTUtil(head, NULL);
}
