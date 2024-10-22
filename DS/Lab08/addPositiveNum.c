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
        printf("%d", n->val);
        n = n->next;
    }
    printf("\n");
}

void addNumbers(Node* num1, Node* num2, Node** result) {
    Node *p1 = num1, *p2 = num2;
    int carry = 0;
    
    while (p1 != NULL || p2 != NULL || carry) {
        int sum = carry;
        if (p1 != NULL) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->val;
            p2 = p2->next;
        }
        carry = sum / 10;
        insertRear(result, sum % 10);
    }
}

int main() {
    Node* num1 = NULL;
    Node* num2 = NULL;
    Node* sum = NULL;
    int digit;

    printf("Enter digits of first number (end with -1): ");
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) break;
        insertRear(&num1, digit);
    }

    printf("Enter digits of second number (end with -1): ");
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) break;
        insertRear(&num2, digit);
    }

    addNumbers(num1, num2, &sum);
    
    printf("Sum: ");
    traverse(sum);

    return EXIT_SUCCESS;
}
