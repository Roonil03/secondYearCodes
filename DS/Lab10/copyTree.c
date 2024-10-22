#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* copyTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

Node* createTreeFromInput() {
    int data;
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    Node* root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = createTreeFromInput();
    printf("Enter right child of %d:\n", data);
    root->right = createTreeFromInput();
    return root;
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    printf("Creating the original binary tree:\n");
    Node* originalTree = createTreeFromInput();
    Node* copiedTree = copyTree(originalTree);
    printf("\nIn-order traversal of the original tree:\n");
    printTree(originalTree);
    printf("\nIn-order traversal of the copied tree:\n");
    printTree(copiedTree);
    return 0;
}
