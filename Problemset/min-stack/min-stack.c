
// @Title: 最小栈 (Min Stack)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-10 23:51:26
// @Runtime: 72 ms
// @Memory: N/A

typedef struct {
    int *element;
    int top;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* NewStack=(MinStack*)malloc(sizeof(MinStack));
    NewStack->element=(int*)malloc(sizeof(int)*maxSize);
    NewStack->top=-1;
    return NewStack;
}

void minStackPush(MinStack* obj, int x) {
    obj->element[++(obj->top)]=x;
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->element[obj->top];
}

int minStackGetMin(MinStack* obj) {
    int min=INT_MAX;
    for(int i=0;i<=obj->top;i++)
    {
        if(min>obj->element[i])
            min=obj->element[i];
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj->element);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
