#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* createTree() {
    int data;
    char choice;

    printf("Do you want to insert a node? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'n' || choice == 'N') {
        return NULL;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    Node* node = createNode(data);

    printf("Inserting left child of %d:\n", data);
    node->left = createTree();

    printf("Inserting right child of %d:\n", data);
    node->right = createTree();

    return node;
}

void preOrder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = NULL;

    printf("Start creating the binary tree:\n");
    root = createTree();

    printf("Pre-order traversal of the binary tree:\n");
    preOrder(root);
    printf("\n");

    return EXIT_SUCCESS;
}
