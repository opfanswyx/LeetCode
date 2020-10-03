
// @Title: 复制带随机指针的链表 (Copy List with Random Pointer)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 14:09:04
// @Runtime: 12 ms
// @Memory: N/A

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	if(NULL==head) return head;

	struct RandomListNode *p=head;
	struct RandomListNode *pt;

	//copy
	while(NULL!=p){
		pt=p->next;
		p->next=malloc(sizeof(struct RandomListNode));
		p->next->label=p->label;
		p->next->next=pt;
		p->next->random=NULL; 
		p=pt;
	};

	//fix random pointer
	p=head;
	while(NULL!=p){
		if(NULL!=p->random){
			p->next->random=p->random->next;
		}
		p=p->next->next;
	};

	//separate
	struct RandomListNode *copyed_head=NULL;
	p=head;
	while(NULL!=p){
		if(NULL!=copyed_head){
			pt->next=p->next;
			pt=pt->next;
		}else{
			copyed_head=p->next;
			pt=copyed_head;
		}
		p->next=p->next->next;
		p=p->next;
	};

	return copyed_head;
}
