
// @Title: 相交链表 (Intersection of Two Linked Lists)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-11 19:29:55
// @Runtime: 16 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *headB_du;
    struct ListNode *headA_du;
    headB_du = headB;
    headA_du = headA;
    int maxa=0;
    int maxb=0;
    int i;
    while(headB_du)
    {
        headB_du=headB_du->next;
        maxb++;
    }
    
    while(headA_du)
    {
        headA_du=headA_du->next;
        maxa++;
    }
    headB_du = headB;
    headA_du = headA;
    
    if(maxa>maxb)
    {
        for(i=0;i<(maxa-maxb);i++)
        {
            headA_du=headA_du->next;
        }
    }else
    {
        for(i=0;i<(maxb-maxa);i++)
        {
            headB_du=headB_du->next;
        }   
    }
    
            
        while(headA_du!=NULL)
        {
            if(headA_du==headB_du)
            {
                return headA_du;
            }else
            {
                headA_du=headA_du->next;
                headB_du=headB_du->next;
            }
        }


    return NULL;
}
