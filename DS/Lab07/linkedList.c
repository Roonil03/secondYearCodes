#include <stdio.h>
#include <stdlib.h>

typedef struct s {
    int val;
    struct s* next;
} Node;

void createNode(int v, Node* n) {
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = (Node*)malloc(sizeof(Node));
    n->next->val = v;
    n->next->next = NULL;
}

void insertionBefore(int v, Node* temp, int ind) {
    if (ind <= 0) {
        printf("Index must be positive.\n");
        return;
    }

    Node* prev = NULL;
    while (temp != NULL && temp->val != ind) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", ind);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = temp;

    if (prev != NULL) {
        prev->next = newNode;
    } else {
        printf("Error: The element to insert before must be non-head.\n");
        return;
    }
}

void insertionAfter(int v, Node* n, int ind) {
    while (n != NULL && n->val != ind) {
        n = n->next;
    }
    if (n == NULL) {
        printf("Element %d not found in the list.\n", ind);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = n->next;
    n->next = newNode;
}

void deleteElement(int v, Node* temp) {
    Node* prev = NULL;
    while (temp != NULL && temp->val != v) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", v);
        return;
    }
    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        printf("Error: Cannot delete the head node in this implementation.\n");
        return;
    }
    free(temp);
}
void traverse(Node* temp) {
    int count = 1;
    while (temp != NULL) {
        printf("Node %d has value: %d\n", count, temp->val);
        temp = temp->next;
        count++;
    }
}
void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void sortList(Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void deleteAlternate(Node* temp) {
    int count = 1;
    Node* prev = NULL;
    while (temp != NULL) {
        if (count % 2 == 0) {
            Node* toDelete = temp;
            prev->next = temp->next;
            temp = temp->next;
            free(toDelete);
        } else {
            prev = temp;
            temp = temp->next;
        }
        count++;
    }
}
void insertSorted(Node** head_ref, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = NULL;
    if (*head_ref == NULL || (*head_ref)->val >= v) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next != NULL && temp->next->val < v) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void freeList(Node* n)
{
    while(n!= NULL){
        Node* temp = n;
        n = n->next;
        free(temp);
    }
}
int main() {
    int choice = 0;
    int exit = 10;
    printf("Give an initial value for list: ");
    int we;
    scanf("%d", &we);

    Node* n = (Node*)malloc(sizeof(Node));
    n->val = we;
    n->next = NULL;
    Node* head = n;
    do {
        printf("1. Create a node\n");
        printf("2. Insert an element before\n");
        printf("3. Insert an element after\n");
        printf("4. Delete an element\n");
        printf("5. Traverse list\n");
        printf("6. Reverse list\n");
        printf("7. Sort the list\n");
        printf("8. Delete every alternate node\n");
        printf("9. Insert element into sorted list\n");
        printf("10. Exit Program\n");
        scanf("%d", &choice);
        int val = -1;
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                createNode(val, head);
                traverse(head);
                break;
            case 2:
                printf("Enter the value to find: ");
                int ind;
                scanf("%d", &ind);
                printf("Enter the element to input: ");
                scanf("%d", &val);
                insertionBefore(val, head, ind);
                traverse(head);
                break;
            case 3:
                printf("Enter the value to find: ");
                scanf("%d", &ind);
                printf("Enter the element to input: ");
                scanf("%d", &val);
                insertionAfter(val, head, ind);
                traverse(head);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &val);
                deleteElement(val, head);
                traverse(head);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                reverse(&head);
                traverse(head);
                break;
            case 7:
                sortList(&head);
                traverse(head);
                break;
            case 8:
                deleteAlternate(head);
                traverse(head);
                break;
            case 9:
                printf("Enter the element to insert into sorted list: ");
                scanf("%d", &val);
                insertSorted(&head, val);
                traverse(head);
                break;
            case 10:
                printf("Exiting Program!\n");
                break;
            default:
                printf("Incorrect input, retry\n");
                break;
        }
    } while (choice != exit);
    freeList(n);
    return EXIT_SUCCESS;
}
