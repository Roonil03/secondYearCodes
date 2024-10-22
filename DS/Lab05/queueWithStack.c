#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int top;
}Stack;
typedef struct{
    Stack s1;
    Stack s2;
}Queue;

void initialize(Stack* s)
{
    s->top  = -1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}
int isFull(Stack* s)
{
    return s->top == MAX - 1;
}

void push(Stack* s, int num)
{
    if(isFull(s))
    {  
        printf("Stack is full!");
        return;
    }
    s->data[++s->top] = num;
}

int pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("The stack is empty. Error: %d",EXIT_FAILURE);
        return EXIT_FAILURE;
    }
    return s->data[s->top--];
}

void enqueue(Queue* q, int value){
    push(&q->s1,value);
}

void transfer(Stack* src, Stack* dest){
    while(!isEmpty(src)){
        push(dest,pop(src));
    }
}

int dequeue(Queue* q)
{
    if(isEmpty(&q->s1)&&isEmpty(&q->s2))
    {
        printf("Error: Queue is empty! Error: %d\n",EXIT_FAILURE);
        return EXIT_FAILURE;
    }
    if(isEmpty(&q->s2))
    {
        transfer(&q->s1,&q->s2);
    }
    return pop(&q->s2);
}

int main()
{
    Queue q;
    initialize(&(q.s1));
    initialize(&(q.s2));
    int value, choice;
    do{
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d",&value);
                enqueue(&q,value);
                break;
            case 2:
                printf("Dequeued value: %d\n",dequeue(&q));
                break;
            case 3:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Retry option\n\n");
                break;
        }
    }while(choice!=3);
    return EXIT_SUCCESS;
}