#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
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

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->data[s->top--];
}

int isPalindrome(char *str) {
    Stack s;
    initialize(&s);
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        push(&s, str[i]);
    }
    int j = (n % 2 == 0) ? n / 2 : n / 2 + 1;
    for (int i = j; i < n; i++) {
        if (pop(&s) != str[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return EXIT_SUCCESS;
}
