#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX][MAX];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX-1;
}

void push(Stack* s, const char* str) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    strncpy(s->data[++s->top], str, MAX-1);
    s->data[s->top][MAX-1] = '\0'; 
}

const char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Error.\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void postfixToInfix(const char* postfix, char* infix) {
    Stack s;
    initialize(&s);
    int len = strlen(postfix);
    
    for (int i = 0; i < len; i++) {
        if (isOperand(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            push(&s, operand);
        } else {
            char op1[MAX];
            char op2[MAX];
            
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));
            
            char temp[MAX];
            snprintf(temp, sizeof(temp), "(%s%c%s)", op2, postfix[i], op1);
            push(&s, temp);
        }
    }
    
    strcpy(infix, pop(&s));
}
void reverse(char* str){
    int n = strlen(str);
    for(int i = 0; i<n/2; i++)
    {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}
int main() {
    char postfix[MAX];
    printf("Enter the prefix expression: ");
    //fgets(postfix,MAX,stdin);
    gets(postfix);
    char infix[MAX];
    reverse(postfix);
    postfixToInfix(postfix, infix);
    reverse(infix);
    for(int i = 0; infix[i]!= '\0';i++)
    {
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    //printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: %s\n", infix);
    
    return EXIT_SUCCESS;
}