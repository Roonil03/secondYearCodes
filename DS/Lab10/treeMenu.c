#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode->left = newNode ->right = NULL;
    return newNode;
}

void inorder(Node* root) // Left Root Right
{
    if(root == NULL) return;
    Node* current = root;
    Node* stack[100];
    int top = -1;
    while(current != NULL || top >= 0)
    {
        while(current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ",current->data);
        current = current->right;
    }
}

void post(Node* root) //Left Right Root
{
    if (root == NULL) return;

    Node* current = root;
    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        Node* temp = stack1[top1--];
        stack2[++top2] = temp;

        if (temp->left) stack1[++top1] = temp->left;
        if (temp->right) stack1[++top1] = temp->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

void pre(Node* root) //Root Left Right
{
    if(root == NULL) return;

    Node* current = root;
    Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        Node* temp = stack[top--];
        printf("%d ", temp->data);

        if (temp->right) stack[++top] = temp->right;
        if (temp->left) stack[++top] = temp->left;
    }
}

void printParent(Node* root, int data)
{
    if (root == NULL) return;

    if (root->left && root->left->data == data) {
        printf("Parent of %d is %d\n", data, root->data);
        return;
    }

    if (root->right && root->right->data == data) {
        printf("Parent of %d is %d\n", data, root->data);
        return;
    }

    printParent(root->left, data);
    printParent(root->right, data);
}

int depth(Node* root)
{
    if(root == NULL) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    if(leftDepth > rightDepth) return leftDepth + 1;
    else return rightDepth + 1;
}

void printAncestors(Node* root, int data) {
    if (root == NULL) return;

    if (root->data == data) {
        printf("%d is the root node\n", data);
        return;
    }

    if (root->left && root->left->data == data) {
        printf("%d ", root->data);
        printAncestors(root, root->data);
        return;
    }

    if (root->right && root->right->data == data) {
        printf("%d ", root->data);
        printAncestors(root, root->data);
        return;
    }

    printAncestors(root->left, data);
    printAncestors(root->right, data);
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode (3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    post(root);
    printf("\n");

    printf("Pre-order traversal: ");
    pre(root);
    printf("\n");

    printParent(root, 5);
    printf("Depth of the tree: %d\n", depth(root));

    printf("Ancestors of 5: ");
    printAncestors(root, 5);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return EXIT_SUCCESS;
}