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

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return op == '^';  // Only '^' is right associative
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
            if (isRightAssociative(postfix[i])) {
                snprintf(temp, sizeof(temp), "(%s%c%s)", op2, postfix[i], op1);
            } else {
                snprintf(temp, sizeof(temp), "(%s%c%s)", op1, postfix[i], op2);
            }
            push(&s, temp);
        }
    }

    strcpy(infix, pop(&s));
}

int main() {
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';  // Remove trailing newline
    char infix[MAX];

    postfixToInfix(postfix, infix);

    printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: %s\n", infix);

    return EXIT_SUCCESS;
}
