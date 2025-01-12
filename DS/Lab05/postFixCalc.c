#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct{
    int top;
    int data[MAX];
}Stack;

void initialize(Stack* s)
{
    s->top = -1;
}
int isEmpty(Stack* s)
{
    return s->top == -1;
}
int isFull(Stack* s)
{
    return s->top == MAX -1;
}

void push(Stack* s, int n)
{
    if(isFull(s))
    {
        printf("Stack is full!");
    }
    s->data[++s->top] = n;
}

int pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty...");
        return EXIT_FAILURE;
    }
    return s->data[s->top--];
}

int eval(char* post)
{
    Stack s;
    initialize(&s);
    int i=0, op1,op2, result;
    while(post[i] != '\0'){
        if(isdigit(post[i]))
        {
            push(&s,post[i]-'0');
        }
        else{
            op2 = pop(&s);
            op1 = pop(&s);
            switch(post[i]){
                case '+':
                result = op1 + op2;
                break;
                case '-':
                result = op1 - op2;
                break;
                case '*':
                result = op1 * op2;
                break;
                case '/':
                if(op2 == 0)
                {
                    return EXIT_FAILURE;
                }
                result = op1 / op2;
                break;
                case '^':
                result = pow(op1,op2);
                break;
                default:
                printf("Invalid operator %d\n",EXIT_FAILURE);
                return EXIT_FAILURE;
            }
            push(&s,result);
        }
        i++;
    }
    if(!isEmpty(&s)){
        result = pop(&s);
        return result;
    }
    {
        printf("Error further!");
        return EXIT_FAILURE;
    }
}

int main() {
    char post[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s",post);
    printf("Result: %d",eval(post));
    return EXIT_SUCCESS;
}
