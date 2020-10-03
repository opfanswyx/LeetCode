
// @Title: 删除排序链表中的重复元素 II (Remove Duplicates from Sorted List II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-07 09:37:20
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
     if (!head || !head->next) return head;

      struct   ListNode tmp;
        tmp.next = head;
       struct  ListNode* pre = &tmp;
       struct  ListNode* cur = head;
        //1,2,2,3,4
//        //pre 0-1-2-2-3-4
        // 0 -cur 1-2-2-3-4
        while(cur){
            if(cur->next && pre->next->val == cur->next->val){
                do{
                    cur = cur->next;
                }
                while(cur->next && pre->next->val == cur->next->val);
                pre->next = cur->next;
            } else{
                pre = pre->next;
            }


            cur = cur->next;
        }
        return tmp.next;
}
#if 0
struct ListNode* deleteDuplicates(struct ListNode* head) {
    int i, j, flag;
    struct ListNode *prevPnt, *pnt, *tmp;
    prevPnt = head;
    pnt = head;
    for(i = 0; ; i++){
        if (pnt != NULL && pnt->next != NULL){ // pnt & pnt->next exists
            if (pnt->val == pnt->next->val){ // equal & rmv
                tmp = pnt->next;
                pnt->next = pnt->next->next;
                free(tmp);
                flag = 1; // flag indicates previous dup or not
            }
            else{ // not equal & move *pnt
                if (flag == 1){ // rmv pnt node
                    tmp = pnt;
                    pnt = pnt->next;
                    if (head == tmp) head = pnt;
                    else  prevPnt->next = pnt;                        
                    free(tmp);
                }
                else{
                    prevPnt = pnt;
                    pnt = pnt->next;
                }
                flag = 0;
            }
        }
        else{ break;} // pnt or pnt0->next not exist
    }
    if (flag == 1){ // rmv the last elem pnt
        tmp = pnt;
        pnt = pnt->next;
        if (head == tmp) head = pnt;
        else  prevPnt->next = pnt;                        
        free(tmp);
    }
    return head;
}
#endif
