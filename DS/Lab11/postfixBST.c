#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* createTree(char* postfix) {
    int length = strlen(postfix);
    Node** stack = (Node**)malloc(length * sizeof(Node*));
    int top = -1;

    for (int i = 0; i < length; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            Node* newNode = createNode(postfix[i]);
            stack[++top] = newNode;
        } else {
            Node* newNode = createNode(postfix[i]);
            if (postfix[i] == '^') {
                newNode->right = stack[top--];
                newNode->left = stack[top--];
            } else {
                newNode->right = stack[top--];
                newNode->left = stack[top--];
            }
            stack[++top] = newNode;
        }
    }

    Node* root = stack[top];
    free(stack);
    return root;
}

int evaluateTree(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->data >= '0' && root->data <= '9') {
        return root->data - '0';
    }

    int leftValue = evaluateTree(root->left);
    int rightValue = evaluateTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        case '^':
            return (int)pow(leftValue, rightValue);
        default:
            return 0;
    }
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    Node* root = createTree(postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("\n");
    printf("Evaluation Result: %d\n", evaluateTree(root));
    return EXIT_SUCCESS;
}