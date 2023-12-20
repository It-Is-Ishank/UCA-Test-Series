// Link to the problem : https://leetcode.com/problems/remove-duplicate-letters/description/

typedef struct {
    int top;
    char* arr;
} Stack;

Stack* create(int size) {
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->top = -1;
    stk->arr = (char*)malloc(size * sizeof(char));
    return stk;
}

bool isEmpty(Stack* stk) {
    return stk->top == -1;
}

void push(Stack* stack, char item) {
    stack->arr[++stack->top] = item;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) return;
    stack->top--;
}

char peek(Stack* stack) {
    if (isEmpty(stack))
        return 0;
    return stack->arr[stack->top];
}

char* removeDuplicateLetters(char* s) {
    int freq[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }
    Stack* stack = create(strlen(s));
    bool exist[26];
    memset(exist, false, sizeof(exist));

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        freq[ch - 'a']--;
        if (exist[ch - 'a'] == true) continue;

        while (!isEmpty(stack) && peek(stack) > ch && freq[peek(stack) - 'a'] > 0) {
            char rem = peek(stack);
            pop(stack);
            exist[rem - 'a'] = false;
        }
        push(stack, ch);
        exist[ch - 'a'] = true;
    }

    char* ans = (char*)malloc((stack->top + 2) * sizeof(char));  // Increased size by 1 for null terminator
    for (int i = 0; i < stack->top + 1; i++) {
        ans[i] = stack->arr[i];
    }
    // Null-terminate the string
    ans[stack->top + 1] = '\0';

    return ans;
}