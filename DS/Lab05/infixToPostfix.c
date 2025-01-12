#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char ch) {
    if (isFull(s)) {
        printf("Stack is full!\n");
    } else {
        s->data[++s->top] = ch;
    }
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0'; // or error handling
    }
    return s->data[s->top--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // or error handling
    }
    return s->data[s->top];
}

int prec(char ch) {
    switch(ch) {
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

int isRightAssociative(char ch) {
    return ch == '^';
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initialize(&s);
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove the '(' from the stack
        } else { // operator
            while (!isEmpty(&s) &&
                   (prec(peek(&s)) > prec(infix[i]) ||
                   (prec(peek(&s)) == prec(infix[i]) && !isRightAssociative(infix[i])))) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char postfix[MAX];
    char infix[MAX];
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin); // Use fgets for safe input
    infix[strcspn(infix, "\n")] = '\0'; // Remove the newline character if present
    infixToPostfix(infix, postfix);
    printf("The postfix expression is: ");
    puts(postfix);
    return EXIT_SUCCESS;
}
