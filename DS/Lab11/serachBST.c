#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    int n;
    printf("How many items present: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int v;
        printf("Enter value %d: ", (i + 1));
        scanf("%d", &v);
        root = insert(root, v);
    }
    inorder(root);
    printf("\n");
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the tree.\n", key);
    } else {
        printf("Element %d not found in the tree.\n", key);
    }
    return EXIT_SUCCESS;
}
