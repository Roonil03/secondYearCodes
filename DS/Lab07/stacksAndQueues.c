#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) return -1;
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) return -1;
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
    return data;
}

void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
    free(stack);
}

void freeQueue(Queue* queue) {
    while (queue->front != NULL) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("1. Push to Stack\n2. Pop from Stack\n3. Enqueue to Queue\n4. Dequeue from Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                printf("Popped from Stack: %d\n", data);
                break;
            case 3:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 4:
                data = dequeue(queue);
                printf("Dequeued from Queue: %d\n", data);
                break;
            case 5:
                freeStack(stack);
                freeQueue(queue);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice\n");
        }
    }
}