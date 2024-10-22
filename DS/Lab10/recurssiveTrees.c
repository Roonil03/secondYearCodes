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

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

// Pre-order traversal (DFS): Root -> Left -> Right
void preOrder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = NULL;
    int data, n, i;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    printf("Pre-order traversal of the binary tree:\n");
    preOrder(root);
    printf("\n");
    return EXIT_SUCCESS;
}
