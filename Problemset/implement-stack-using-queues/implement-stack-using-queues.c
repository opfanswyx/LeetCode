
// @Title: 用队列实现栈 (Implement Stack using Queues)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-15 15:50:48
// @Runtime: 0 ms
// @Memory: N/A

typedef struct{
    int *q;
    int size;
    int front;
    int rear;
}Queue;
typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

int queueIsEmpty(Queue *q){
    if(q->front==-1 && q->rear==-1){
        printf("\nQueue is EMPTY\n");
        return 1;
    }
    return 0;
}

int queueIsFull(Queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    return 0;
}

int queueTop(Queue *q){
    if(queueIsEmpty(q)){
        return -1;
    }
    return q->q[q->front];
}

int queuePop(Queue *q){
    if(queueIsEmpty(q)){
        return -1;
    }
    int item = q->q[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front++;
    }
    return item;
}

void queuePush(Queue *q, int val){
    if(queueIsFull(q))
    {
        printf("\nQUEUE is FULL\n");
        return;
    }
    if(queueIsEmpty(q)){
        q->front++;
        q->rear++;
    }else{
        q->rear++;
    }
    q->q[q->rear]=val;
}

Queue *queueCreate(int maxSize){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=-1;
    q->size=maxSize;
    q->q=(int*)malloc(sizeof(int)*maxSize);
    return q;
}
/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *stack=(MyStack*)malloc(sizeof(MyStack));
    stack->q1=queueCreate(maxSize);
    stack->q2=queueCreate(maxSize);
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    queuePush(obj->q2,x);
    while(!queueIsEmpty(obj->q1)){
        int item=queuePop(obj->q1);
        queuePush(obj->q2,item);
    }
    Queue *temp=obj->q1;
    obj->q1=obj->q2;
    obj->q2=temp;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int item=queuePop(obj->q1);
    return item;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(!queueIsEmpty(obj->q1))
        return queueTop(obj->q1);
    return -1;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(queueIsEmpty(obj->q1))
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
