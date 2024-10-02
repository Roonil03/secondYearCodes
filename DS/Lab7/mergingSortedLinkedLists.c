#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

Node* mergeLists(Node* X, Node* Y) {
    Node* Z = NULL;
    Node** tail = &Z;
    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            *tail = X;
            X = X->next;
        } else {
            *tail = Y;
            Y = Y->next;
        }
        tail = &((*tail)->next);
    }
    *tail = (X != NULL) ? X : Y;
    return Z;
}

void traverseLinkedList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeLinkedList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n1, n2;
    printf("Enter the number of nodes in list X: ");
    scanf("%d", &n1);
    printf("Enter the nodes of list X in non-decreasing order:\n");
    Node* X = createLinkedList(n1);
    printf("Enter the number of nodes in list Y: ");
    scanf("%d", &n2);
    printf("Enter the nodes of list Y in non-decreasing order:\n");
    Node* Y = createLinkedList(n2);
    Node* Z = mergeLists(X, Y);
    printf("Merged Linked List Z: ");
    traverseLinkedList(Z);
    freeLinkedList(Z);
    return EXIT_SUCCESS;
}
