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

int areTreesEqual(Node* tree1, Node* tree2) {
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    return (tree1->data == tree2->data) &&
           areTreesEqual(tree1->left, tree2->left) &&
           areTreesEqual(tree1->right, tree2->right);
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

Node* createTreeFromInput() {
    Node* root = NULL;
    int n, data;
    printf("Enter the number of nodes for the tree: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    return root;
}

int main() {
    printf("Creating first binary tree:\n");
    Node* tree1 = createTreeFromInput();
    printf("Creating second binary tree:\n");
    Node* tree2 = createTreeFromInput();
    // Check if the two trees are equal
    if (areTreesEqual(tree1, tree2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }
    return EXIT_SUCCESS;
}