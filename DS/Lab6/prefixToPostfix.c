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
    return s->top == MAX - 1;
}

void push(Stack* s, const char* str) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    strncpy(s->data[++s->top], str, MAX - 1);
    s->data[s->top][MAX - 1] = '\0';
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

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void charInitialize(CharStack* s) {
    s->top = -1;
}

int charIsFull(CharStack* s) {
    return s->top == MAX - 1;
}

int charIsEmpty(CharStack* s) {
    return s->top == -1;
}

void charPush(CharStack* s, char ch) {
    if (charIsFull(s)) {
        printf("Stack is full!\n");
    }
    s->data[++s->top] = ch;
}

char charPop(CharStack* s) {
    if (charIsEmpty(s)) {
        return '\0';
    }
    return s->data[s->top--];
}

char charPeek(CharStack* s) {
    if (charIsEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    CharStack s;
    charInitialize(&s);
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            charPush(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!charIsEmpty(&s) && charPeek(&s) != '(') {
                postfix[k++] = charPop(&s);
            }
            charPop(&s);
        } else {
            while (!charIsEmpty(&s) && precedence(charPeek(&s)) >= precedence(infix[i])) {
                postfix[k++] = charPop(&s);
            }
            charPush(&s, infix[i]);
        }
        i++;
    }
    while (!charIsEmpty(&s)) {
        postfix[k++] = charPop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char prefix[MAX];
    char infix[MAX];
    char postfix[MAX];

    printf("Enter the prefix expression: ");
    fgets(prefix, MAX, stdin);
    prefix[strcspn(prefix, "\n")] = '\0';

    reverse(prefix);
    postfixToInfix(prefix, infix);
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return EXIT_SUCCESS;
}
