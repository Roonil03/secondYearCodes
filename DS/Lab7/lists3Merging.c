#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int n) {
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

Node* mergeLists(Node* list1, Node* list2) {
    Node* list3 = NULL;
    Node** tail = &list3;
    while (list1 != NULL && list2 != NULL) {
        *tail = list1;
        tail = &((*tail)->next);
        list1 = list1->next;
        *tail = list2;
        tail = &((*tail)->next);
        list2 = list2->next;
    }
    *tail = (list1 != NULL) ? list1 : list2;
    return list3;
}

void traverseList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n1, n2;
    printf("Enter the number of nodes in list1: ");
    scanf("%d", &n1);
    printf("Enter the nodes of list1:\n");
    Node* list1 = createList(n1);
    printf("Enter the number of nodes in list2: ");
    scanf("%d", &n2);
    printf("Enter the nodes of list2:\n");
    Node* list2 = createList(n2);
    Node* list3 = mergeLists(list1, list2);
    printf("Merged List3: ");
    traverseList(list3);
    freeList(list3);
    return EXIT_SUCCESS;
}
