
// @Title: 两数相加 (Add Two Numbers)
// @Author: opfanswyx@outlook.com
// @Date: 2018-02-19 19:56:57
// @Runtime: 24 ms
// @Memory: N/A

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL || l2 == NULL)
    {
        fprintf(stderr, "error input");
        exit(1);
    }
    
    struct ListNode *head, *empty;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    empty = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(head == NULL || empty == NULL)
    {
        fprintf(stderr, "fail to malloc");
        exit(1);
    }
    
    empty->val = 0;
    empty->next = NULL;
    
    struct ListNode *br = head, *p1 = l1, *p2 = l2;
    int carrier = 0;
    while(p1 != NULL || p2 != NULL)
    {
        //如果链表是空则用empty链表替代，防止后边的数学计算出错
        if(p1 == NULL)
            p1 = empty;
        else if(p2 == NULL)
            p2 = empty;
        
        br->val = (p1->val + p2->val + carrier)%10;
        carrier = (p1->val + p2->val + carrier)/10;
        p1 = p1->next;
        p2 = p2->next;
        if(p1 != NULL || p2 != NULL)
        {
            br->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            if(br->next == NULL)
            {
                fprintf(stderr, "fail to malloc");
                exit(1);
            }
            br = br->next;
            br->next = NULL;
        }
    }
    if(carrier > 0)
    {
        br->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(br->next == NULL)
        {
            fprintf(stderr, "fail to malloc");
            exit(1);
        }
        br->next ->val = carrier;
        br->next ->next = NULL;
    }
    free(empty);
    return head;
}
