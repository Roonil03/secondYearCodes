#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NUM_STACKS 3

typedef struct {
    int top[NUM_STACKS];
    int data[MAX_SIZE];
} MultipleStacks;

void initialize(MultipleStacks *ms) {
    for (int i = 0; i < NUM_STACKS; i++) {
        ms->top[i] = -1;
    }
}

int isEmpty(MultipleStacks *ms, int stack_num) {
    return ms->top[stack_num] == -1;
}

int isFull(MultipleStacks *ms) {
    return ms->top[NUM_STACKS - 1] == MAX_SIZE - 1;
}

void push(MultipleStacks *ms, int stack_num, int x) {
    if (isFull(ms)) {
        printf("Stack overflow\n");
        return;
    }
    ms->data[++ms->top[stack_num]] = x;
}

int pop(MultipleStacks *ms, int stack_num) {
    if (isEmpty(ms, stack_num)) {
        printf("Stack underflow\n");
        return -1;
    }
    return ms->data[ms->top[stack_num]--];
}

void display(MultipleStacks *ms, int stack_num) {
    if (isEmpty(ms, stack_num)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack %d: ", stack_num + 1);
    for (int i = ms->top[stack_num]; i >= 0; i--) {
        printf("%d ", ms->data[i]);
    }
    printf("\n");
}

int main() {
    MultipleStacks ms;
    int choice, stack_num, data;

    initialize(&ms);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1, 2, or 3): ");
                scanf("%d", &stack_num);
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&ms, stack_num - 1, data);
                break;
            case 2:
                printf("Enter stack number (1, 2, or 3): ");
                scanf("%d", &stack_num);
                printf("Popped element: %d\n", pop(&ms, stack_num - 1));
                break;
            case 3:
                printf("Enter stack number (1, 2, or 3): ");
                scanf("%d", &stack_num);
                display(&ms, stack_num - 1);
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice\n");
        }
    }

    return EXIT_SUCCESS;
}
