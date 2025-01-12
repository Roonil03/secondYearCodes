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

int areMirrors(Node* tree1, Node* tree2) {
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    return (tree1->data == tree2->data) &&
           areMirrors(tree1->left, tree2->right) &&
           areMirrors(tree1->right, tree2->left);
}

Node* createTreeFromInput() {
    int data;
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    Node* root = createNode(data);
    // Recursively create left and right children
    printf("Enter left child of %d:\n", data);
    root->left = createTreeFromInput();
    printf("Enter right child of %d:\n", data);
    root->right = createTreeFromInput();
    return root;
}

int main() {
    printf("Creating first binary tree:\n");
    Node* tree1 = createTreeFromInput();
    printf("\nCreating second binary tree:\n");
    Node* tree2 = createTreeFromInput();
    if (areMirrors(tree1, tree2)) {
        printf("The two trees are mirror images of each other.\n");
    } else {
        printf("The two trees are not mirror images of each other.\n");
    }
    return EXIT_SUCCESS;
}
