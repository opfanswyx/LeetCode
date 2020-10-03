
// @Title: 旋转链表 (Rotate List)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-02 15:01:11
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int i,size,tmp;
    struct ListNode *loc, *ltmp, *end;
    loc=head;
    for(i=0;;i++){
        if(loc!=NULL){
            end=loc;
            loc=loc->next;
        }
        else
            break;
    }
    size=i;
    if(size==0||k%size==0)
        return head;
    else{
        tmp=k%size;
        loc=head;
        for(i=0;i<size-tmp-1;i++)
            loc=loc->next;
        ltmp=loc->next;
        loc->next=NULL;
        end->next=head;
        head=ltmp;
    }
    return head;
}
