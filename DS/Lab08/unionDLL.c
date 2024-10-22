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

void traverse(Node* head) {
    Node* n = head;
    while (n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

void unionLists(Node* X1, Node* X2, Node** result) {
    Node* n = X1;
    while (n != NULL) {
        insertRear(result, n->val);
        n = n->next;
    }
    n = X2;
    while (n != NULL) {
        Node* temp = *result;
        int found = 0;
        while (temp != NULL) {
            if (temp->val == n->val) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertRear(result, n->val);
        }
        n = n->next;
    }
}

void intersectionLists(Node* X1, Node* X2, Node** result) {
    Node* n1 = X1;
    while (n1 != NULL) {
        Node* n2 = X2;
        while (n2 != NULL) {
            if (n1->val == n2->val) {
                insertRear(result, n1->val);
                break;
            }
            n2 = n2->next;
        }
        n1 = n1->next;
    }
}

int main() {
    Node* X1 = NULL;
    Node* X2 = NULL;
    Node* unionResult = NULL;
    Node* intersectionResult = NULL;
    int value;

    printf("Enter values for list X1 (end with -1): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        insertRear(&X1, value);
    }

    printf("Enter values for list X2 (end with -1): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        insertRear(&X2, value);
    }

    unionLists(X1, X2, &unionResult);
    intersectionLists(X1, X2, &intersectionResult);

    printf("Union of X1 and X2: ");
    traverse(unionResult);

    printf("Intersection of X1 and X2: ");
    traverse(intersectionResult);

    return EXIT_SUCCESS;
}
