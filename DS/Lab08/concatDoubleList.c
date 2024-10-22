#include <stdio.h>
#include <stdlib.h>

typedef struct s {
    struct s* next;
    struct s* prev;
    int val;
} Node;

void insertRear(Node** head, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node* n = *head;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = newNode;
    newNode->prev = n;
}

void concatenate(Node** X1, Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
        return;
    }
    Node* n = *X1;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = X2;
    if (X2 != NULL) {
        X2->prev = n;
    }
}

void traverse(Node* head) {
    Node* n = head;
    while (n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

int main() {
    Node* X1 = NULL;
    Node* X2 = NULL;
    int value;

    printf("Enter values for list X1 (end with -1): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) 
            break;
        insertRear(&X1, value);
    }

    printf("Enter values for list X2 (end with -1): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) 
            break;
        insertRear(&X2, value);
    }

    concatenate(&X1, X2);
    traverse(X1);
    
    return EXIT_SUCCESS;
}
