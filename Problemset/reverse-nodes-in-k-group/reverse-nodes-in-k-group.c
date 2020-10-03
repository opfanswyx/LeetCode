
// @Title: K 个一组翻转链表 (Reverse Nodes in k-Group)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 14:16:23
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* pNode, int iK) {
    if (iK == 1) {
        return pNode;
    }
    struct ListNode *ttmp = (reverse(pNode->next, iK - 1));
    ttmp->next = pNode;
    return pNode;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head) {
        return head;
    }
    
    struct ListNode *result, *tmpHead, *tmpNow, *tmpEnd, *resEnd;
    result = (struct ListNode*) malloc (sizeof(struct ListNode));
    result->next = NULL;
    
    int count = 0;
    tmpHead = head;
    tmpNow = head;
    resEnd = result;
    
    while (tmpNow) {
        count++;
        
        if (count == k) {
            tmpEnd = tmpNow;
            tmpNow = tmpNow->next;
            reverse(tmpHead, k);
            resEnd->next = tmpEnd;
            resEnd = tmpHead;
            tmpHead->next = tmpNow;
            tmpHead = tmpNow;
            count = 0;
            continue;
        }
        
        tmpNow = tmpNow->next;
    }
    
    if (!(result->next)) {
        return head;
    }
    
    return result->next;
}
