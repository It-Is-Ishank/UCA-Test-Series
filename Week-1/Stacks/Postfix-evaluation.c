#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> 

typedef struct{
    int top;
    int size;
    int *arr;
} Stack;

Stack* create(int size){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->top=-1;
    stk->size = size;
    stk->arr = (int*)malloc(size * sizeof(int));
    return stk;
}
bool isEmpty(Stack* stk){
    return stk->top == -1;
}

int peek(Stack* stk){
    if(isEmpty(stk)) return 0;
       
    return stk->arr[stk->top];
}
      
int pop(Stack* stk){
    return stk->arr[stk->top--];
}   
     
void push(Stack* stk,int item){
    stk->arr[++stk->top] = item;
}   
       


int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2; 
        case '-':
            return operand1 - operand2;  
        case '*':
            return operand1 * operand2;  
        case '/':
            
            return operand1 / operand2;  
    }
    return 0;
}
       
void evaluateExp() {
    int ans = 0;
    char inp[1000];
    scanf(" %[^\n]", inp);  // Use "%[^\n]" to read the entire line, including spaces
    char* token = strtok(inp, " ");

    Stack* stack = create(1000);

    while (token != NULL) {
        
        if (token[0] == '?') {
            ans = peek(stack);
            break;
        } else if (isdigit(token[0])) {
            int value = atoi(token);
            push(stack, value);
            
        } else {
            int operation = performOperation(pop(stack), pop(stack), token[0]);
            
                
            push(stack, operation);
        }

        token = strtok(NULL, " ");
    }
    
    free(stack->arr);
    free(stack);

    printf("%d\n", ans);
}

int main() {
    
    int testCases;
    scanf("%d",&testCases);
    for(int i=0;i<testCases;i++){
        evaluateExp();
    }
    
}
