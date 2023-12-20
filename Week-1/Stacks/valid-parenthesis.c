// link to the problem : https://leetcode.com/problems/valid-parentheses/description/

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

bool checkPair(char val1, char val2) {
    return (val1 == '(' && val2 == ')') || (val1 == '[' && val2 == ']') || (val1 == '{' && val2 == '}');
}

bool isValid(char* s) {
    int len = strlen(s);
    struct Stack* stack = create(len);

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(stack, s[i]);
        } else {
            if (isEmpty(stack)) {
                // Unmatched closing bracket
                free(stack->arr);
                free(stack);
                return false;
            } else if (!checkPair(peek(stack), s[i])) {
                // Mismatched opening and closing brackets
                free(stack->arr);
                free(stack);
                return false;
            }
            pop(stack);
        }
    }

    bool result = isEmpty(stack);

    // Free memory before returning
    free(stack->arr);
    free(stack);

    return result;
}
