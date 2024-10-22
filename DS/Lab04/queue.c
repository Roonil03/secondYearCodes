#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int front, rear, size;
    int queue[MAX];
} circularQueue;

void initialize(circularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
    cq->size = 0;
}

int isEmpty(circularQueue *cq) {
    return cq->size == 0;
}

int isFull(circularQueue *cq) {
    return cq->size == MAX;
}

void enqueue(circularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX;
    cq->queue[cq->rear] = value;
    cq->size++;
    printf("%d enqueued to queue\n", value);
}

int dequeue(circularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Return -1 to indicate an error
    }
    int value = cq->queue[cq->front];
    cq->front = (cq->front + 1) % MAX;
    cq->size--;
    if (isEmpty(cq)) {
        cq->front = -1;
        cq->rear = -1;
    }
    return value;
}

void displayQueue(circularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = 0; i < cq->size; i++) {
        printf("%d ", cq->queue[(cq->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    circularQueue cq;
    initialize(&cq);
    int d=0;
    do{
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit Program\n");
        scanf("%d",&d);
        switch(d){
            default:
            printf("Please retry\n");
            break;
            case 1:
            printf("Enter the number to enqueue");
            int n;
            scanf("%d",&n);
            enqueue(&cq,n);
            break;
            case 2:
            printf("Number dequeued is: %d",dequeue(&cq));
            break;
            case 3:
            printf("Displaying the queue:\n");
            displayQueue(&cq);
            break;
            case 4:
            printf("Exiting program!");
            break;
        }
    }while(d!=4);
    return EXIT_SUCCESS;
}
