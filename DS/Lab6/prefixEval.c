#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} Stack;

void push(Stack* s, int value);
int pop(Stack* s);
int isEmpty(Stack* s);
int evaluatePrefix(char* exp);

int main() {
    char prefix[MAX];
    
    printf("Enter the prefix expression: ");
    if (fgets(prefix, sizeof(prefix), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    
    size_t len = strlen(prefix);
    if (len > 0 && prefix[len - 1] == '\n') {
        prefix[len - 1] = '\0';
    }
    
    int result = evaluatePrefix(prefix);
    printf("The result of the prefix expression is: %d\n", result);
    
    return EXIT_SUCCESS;
}

void push(Stack* s, int value) {
    if (s->top >= (MAX - 1)) {
        fprintf(stderr, "Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[(s->top)--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int evaluatePrefix(char* exp) {
    Stack s;
    s.top = -1;  

    int length = strlen(exp);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            if (isEmpty(&s)) {
                fprintf(stderr, "Error: Not enough operands.\n");
                exit(EXIT_FAILURE);
            }
            int op1 = pop(&s);

            if (isEmpty(&s)) {
                fprintf(stderr, "Error: Not enough operands.\n");
                exit(EXIT_FAILURE);
            }
            int op2 = pop(&s);

            switch (exp[i]) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': 
                    if (op2 == 0) {
                        fprintf(stderr, "Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&s, op1 / op2); break;
                default:
                    fprintf(stderr, "Error: Invalid operator %c\n", exp[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (!isEmpty(&s)) {
        return pop(&s);
    } else {
        fprintf(stderr, "Error: Invalid prefix expression.\n");
        exit(EXIT_FAILURE);
    }
}
