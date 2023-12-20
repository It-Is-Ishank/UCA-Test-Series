// Link to the problem : https://leetcode.com/problems/implement-queue-using-stacks/description/

struct Stack {
    int top;
    int maxSize;
    char* arr;
};

struct Stack* create(int max) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = max;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->maxSize * sizeof(char));
    return stack;
}

bool isEmpty(struct Stack* stk) {
    return stk->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->arr[++stack->top] = item;
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) return;
    stack->top--;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return 0;
    return stack->arr[stack->top];
}


typedef struct {
    struct Stack* s1;
    struct Stack* s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->s1 = create(101);
    queue->s2 = create(101);


    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->s1,x);
}

int myQueuePop(MyQueue* obj) {
    while(!isEmpty(obj->s1)){
        push(obj->s2,peek(obj->s1));
        pop(obj->s1);
    }
    int ans = peek(obj->s2);
    pop(obj->s2);
    while(!isEmpty(obj->s2)){
        push(obj->s1,peek(obj->s2));
        pop(obj->s2);
    }
    return ans;

}

int myQueuePeek(MyQueue* obj) {
    while(!isEmpty(obj->s1)){
        push(obj->s2,peek(obj->s1));
        pop(obj->s1);
    }
    int ans = peek(obj->s2);
    while(!isEmpty(obj->s2)){
        push(obj->s1,peek(obj->s2));
        pop(obj->s2);
    }
    return ans;
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1->arr);
    free(obj->s1);
    free(obj->s2->arr);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/