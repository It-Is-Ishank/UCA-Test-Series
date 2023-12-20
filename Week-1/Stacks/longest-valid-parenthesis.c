// link to the problem: https://leetcode.com/problems/longest-valid-parentheses/description/

typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* create(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    stack->arr[++stack->top] = value;
}

void pop(Stack* stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    }
}

int peek(Stack* stack) {
    return stack->arr[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int longestValidParentheses(char* s) {
    int max = 0;
    Stack* stack = create(strlen(s) + 1);
    push(stack, -1);  // Initialize the stack with -1 as the base

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            push(stack, i);
        } else {
            pop(stack);
            if (!isEmpty(stack)) {
                max = (i - peek(stack) > max) ? i - peek(stack) : max;
            } else {
                // Update the base index if the stack is empty
                push(stack, i);
            }
        }
    }

    free(stack->arr);
    free(stack);

    return max;
}