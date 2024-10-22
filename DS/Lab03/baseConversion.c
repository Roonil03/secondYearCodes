#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int data[MAX_SIZE];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++s->top] = x;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

void convertToBase(int num, int base) {
    Stack s;
    initialize(&s);
    while (num > 0) {
        push(&s, num % base);
        num /= base;
    }
    printf("Equivalent number in base %d: ", base);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int num, base;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Enter the base: ");
    scanf("%d", &base);
    convertToBase(num, base);
    return EXIT_SUCCESS;
}
