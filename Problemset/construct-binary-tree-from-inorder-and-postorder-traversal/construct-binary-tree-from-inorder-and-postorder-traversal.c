
// @Title: 从中序与后序遍历序列构造二叉树 (Construct Binary Tree from Inorder and Postorder Traversal)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-14 10:15:49
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* pNode;

int findInArray(int* array , int aSize , int pos)       //find the root-val position in inorder array
{
        for (int i = aSize - 1 ; i >= 0 ; i --)
                if (array[i] == pos)
                        return i;
        return -1;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
        //使用后续遍历来确定根节点，辅助中序遍历划分左右子树
        pNode root      = NULL;
        if (postorderSize <= 0)
                return NULL;
        root    = (pNode)calloc(1 , sizeof(struct TreeNode));
        //Get root from the last element in postorder
        //从后续遍历的最后一个元素取得根节点
        root->val       = postorder[postorderSize - 1];
        if (postorderSize <= 1)
                return root;
        //Find root's position in inorder
        //找到根节点的元素在中序遍历数组中的位置
        int v   = findInArray(inorder , inorderSize , root->val);
        if (v == -1)
                return NULL;
        //the root divides inorder into [0 ... v - 1] root [v + 1 ... max]
        //根节点将中序遍历数组划分成左右子树，然后递归，先创建右子树
        root->right     = buildTree(inorder + v + 1, inorderSize - v - 1, postorder + postorderSize - inorderSize + v , inorderSize - v - 1);
        root->left      = buildTree(inorder , v , postorder , v);
        return root;
}
