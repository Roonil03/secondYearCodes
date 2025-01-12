#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter data for node %d: ", n);
    scanf("%d", &newNode->data);
    newNode->next = createLinkedList(n - 1);
    return newNode; 
}

void traverseLinkedList(Node* head) {
    if (head == NULL) {
        return;
    }
    printf("%d -> ", head->data);
    traverseLinkedList(head->next);
}

void freeLinkedList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    Node* head = createLinkedList(n);
    printf("Linked List: ");
    traverseLinkedList(head);
    printf("NULL\n");
    freeLinkedList(head);
    return 0;
}
