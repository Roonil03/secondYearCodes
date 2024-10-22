#include <stdio.h>
#include <stdlib.h>

typedef struct s {
    struct s* prev;
    struct s* next;
    int val;
} Node;

void insertNode(Node** head, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void deleteNode(Node** head, int v) {
    if (*head == NULL) return;

    Node* n = *head;
    Node* toDelete = NULL;

    do {
        if (n->val == v) {
            toDelete = n;
            if (n->next == n) {
                *head = NULL;
            } else {
                n->prev->next = n->next;
                n->next->prev = n->prev;
                if (n == *head) {
                    *head = n->next;
                }
            }
            free(toDelete);
            return;
        }
        n = n->next;
    } while (n != *head);
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* n = head;
    int i = 0;
    do {
        printf("Node %d: %d\n", (i + 1), n->val);
        n = n->next;
        i++;
    } while (n != head);
}

void deleteList(Node** head) {
    if (*head == NULL) return;
    Node* current = *head;
    Node* temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *head);
    *head = NULL;
}

int main() {
    int gs;
    int v;
    Node* head = NULL;
    do {
        printf("\n1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("4. Exit Program\n");
        scanf("%d", &gs);
        switch (gs) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &v);
                insertNode(&head, v);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &v);
                deleteNode(&head, v);
                break;
            case 3:
                printf("Printing the list: \n");
                printList(head);
                break;
            case 4:
                deleteList(&head);
                return EXIT_SUCCESS;
            default:
                printf("Try again...\n");
                break;
        }
    } while (1);
}