
// @Title: 填充每个节点的下一个右侧节点指针 (Populating Next Right Pointers in Each Node)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-15 19:10:13
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
struct TreeLinkNode * queue[99999];
 int pre;
 int p;
void connect(struct TreeLinkNode *root) {
    if (root == NULL) return;
    pre = 0;
    p = 0;
    queue[p++] = root;
    while(pre != p){
        //printf("pre is %d , [pre] is %d , p is %d , [p-1] is %d\n" , pre , queue[pre]->val, p , queue[p-1]->val);
        int new_p = p;
        int new_pre = p;
        for (int tmp = pre;tmp < p;tmp++){
            if (queue[tmp]->left && queue[tmp]->right){
                queue[new_p++] = queue[tmp]->left;
                queue[new_p++] = queue[tmp]->right;
            }
            if (tmp + 1 < p){
                queue[tmp]->next = queue[tmp+1];
            }else{
                queue[tmp]->next = NULL;
            }
        }
        p = new_p;
        pre = new_pre;
    }
}
