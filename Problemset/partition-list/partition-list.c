
// @Title: 分隔链表 (Partition List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-08 09:35:46
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode * pnode;
struct ListNode* partition(struct ListNode* head, int x) {
    pnode lt = (pnode)malloc(sizeof(struct ListNode));
    pnode gt = (pnode)malloc(sizeof(struct ListNode));
    if(!head || !head->next)
        return head;
    pnode cur = head;
    pnode lttmp = lt;
    pnode gttmp = gt;
    while(cur){
        pnode tmp = cur;
        if(tmp->val < x){
            lttmp->next = cur;
            lttmp = lttmp->next;
        }
        else{
        gttmp->next = cur;
        gttmp = gttmp->next;
        }
        cur = cur->next;
    }
    gttmp->next = NULL;
    lttmp->next = gt->next;
    head = lt->next;
    free(lt);
    free(gt);
    return head;
}
