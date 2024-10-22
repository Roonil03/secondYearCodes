#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int bool;

typedef struct {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
void push(Stack *s, char item);
char pop(Stack *s);
char peek(Stack *s);
bool isMatchingPair(char character1, char character2);
bool areParenthesesBalanced(const char *expression);

int main() {
    char expression[MAX];
    
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin); 

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char item) {
    if (!isFull(s)) {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0'; 
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

bool isMatchingPair(char character1, char character2) {
    return (character1 == '(' && character2 == ')') ||
           (character1 == '[' && character2 == ']') ||
           (character1 == '{' && character2 == '}');
}

bool areParenthesesBalanced(const char *expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&stack) || !isMatchingPair(peek(&stack), ch)) {
                return 0;
            }
            pop(&stack);
        }
    }

    return isEmpty(&stack);
}
