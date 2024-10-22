#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    Node** queue = (Node**)malloc(100 * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
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
    printf("Level Order Traversal of the BST:\n");
    levelOrderTraversal(root);
    return EXIT_SUCCESS;
}