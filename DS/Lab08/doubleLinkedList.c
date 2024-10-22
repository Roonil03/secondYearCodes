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

void deleteRear(Node** head) {
    if (*head == NULL) return;
    Node* n = *head;
    while (n->next != NULL) {
        n = n->next;
    }
    if (n->prev != NULL) {
        n->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(n);
}

void insertMiddle(Node** head, int pos, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL || pos == 0) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    Node* n = *head;
    for (int i = 0; i < pos - 1 && n != NULL; i++) {
        n = n->next;
    }
    if (n == NULL) {
        free(newNode);
        return;
    }
    newNode->next = n->next;
    newNode->prev = n;
    if (n->next != NULL) {
        n->next->prev = newNode;
    }
    n->next = newNode;
}

void deleteMiddle(Node** head, int pos) {
    if (*head == NULL) return;
    Node* n = *head;
    for (int i = 0; i < pos && n != NULL; i++) {
        n = n->next;
    }
    if (n == NULL) return;
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        *head = n->next;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    }
    free(n);
}

void insertAfter(Node** head, int target, int v) {
    Node* n = *head;
    while (n != NULL && n->val != target) {
        n = n->next;
    }
    if (n == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = n->next;
    newNode->prev = n;
    if (n->next != NULL) {
        n->next->prev = newNode;
    }
    n->next = newNode;
}

void insertBefore(Node** head, int target, int v) {
    Node* n = *head;
    while (n != NULL && n->val != target) {
        n = n->next;
    }
    if (n == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = n;
    newNode->prev = n->prev;
    if (n->prev != NULL) {
        n->prev->next = newNode;
    } else {
        *head = newNode;
    }
    n->prev = newNode;
}

void traverse(Node* head) {
    Node* n = head;
    while (n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

void reverse(Node** head) {
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    Node* head = NULL;
    int choice, value, pos;
    while (1) {
        printf("1. Insert at rear\n2. Delete from rear\n3. Insert at position\n4. Delete from position\n5. Insert after\n6. Insert before\n7. Traverse\n8. Reverse\n9. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(&head, value);
                break;
            case 2:
                deleteRear(&head);
                break;
            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &value);
                insertMiddle(&head, pos, value);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteMiddle(&head, pos);
                break;
            case 5:
                printf("Enter target and value: ");
                scanf("%d %d", &pos, &value);
                insertAfter(&head, pos, value);
                break;
            case 6:
                printf("Enter target and value: ");
                scanf("%d %d", &pos, &value);
                insertBefore(&head, pos, value);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                reverse(&head);
                break;
            case 9:
                return EXIT_SUCCESS;
        }
    }
}
