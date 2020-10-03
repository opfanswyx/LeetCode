
// @Title: 两数之和 (Two Sum)
// @Author: opfanswyx@outlook.com
// @Date: 2019-12-30 17:36:15
// @Runtime: 8 ms
// @Memory: 32.6 MB



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node{
    int index;
    int data;
}Node;

typedef struct HashTable{
    Node *element;
    int size;
}HashTable;

HashTable * HashTableInit(int size){
    HashTable* table;

    if(size <= 0){
        return NULL;
    }

    table = (HashTable*)malloc(sizeof(HashTable));
    if(NULL == table){
        return NULL;
    }

    table->size = size;

    table->element = (Node*)malloc(sizeof(Node) * size);
    if(NULL == table->element){
        return NULL;
    }
    memset(table->element, 0xff, sizeof(Node) * size);
    return table;
}

static int HashAddrGet(int data, HashTable *table){
    int addr = data % table->size;
    return (addr >= 0) ? addr : addr + table->size;
}

void HashInsert(HashTable *table, int index, int data){
    int addr = HashAddrGet(data, table);
    while(table->element[addr].index != -1){
        addr = (addr + 1) % table->size;
    }
    table->element[addr].index = index;
    table->element[addr].data = data;
    return;
}

Node *HashFind(HashTable *table, int data){
    int tmp, addr;
    tmp = addr = HashAddrGet(data,table);

    do{
        if(table->element[addr].index == -1){
            return NULL;
        }
        if(table->element[addr].data == data){
            return &table->element[addr];
        }

        addr = (addr + 1) % table->size;
    }while(addr != tmp);
    return NULL;
}

void HashFree(HashTable *table){
    if(NULL == table){
        return;
    }
    if(NULL != table->element){
        free(table->element);
    }

    free(table);
    return;
}

#define MAX_TABLE_LEN 100000

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int *ret = NULL;
    HashTable *table = NULL;
    Node *node = NULL;

    ret = (int *)malloc(sizeof(int) * 2);
    if (NULL == ret) {
        *returnSize = 0;
        return NULL;
    }
    memset(ret, 0, sizeof(int) * 2);

    table = HashTableInit(MAX_TABLE_LEN);
    if(NULL == table){
        *returnSize = 0;
        return NULL;
    }

    for(i = 0; i < numsSize; i++){
        node = HashFind(table, target - nums[i]);
        if(node != NULL){
            ret[0] = node->index;
            ret[1] = i;
            break;
        }else{
            HashInsert(table, i, nums[i]);
        }
    }

    HashFree(table);
    *returnSize = 2;
    return ret;
}


