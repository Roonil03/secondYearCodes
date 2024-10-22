#include <stdio.h>
#include <stdlib.h>

typedef struct s {
    int coeff;
    int exp;
    struct s* next;
    struct s* prev;
} Node;

void createNode(Node** head, int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;
    newNode->prev = newNode;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* n1 = poly1;
    Node* n2;

    do {
        n2 = poly2;
        do {
            int newCoeff = n1->coeff * n2->coeff;
            int newExp = n1->exp + n2->exp;
            Node* existing = result;

            while (existing != NULL && existing->exp != newExp) {
                existing = existing->next;
            }

            if (existing != NULL) {
                existing->coeff += newCoeff;
            } else {
                createNode(&result, newCoeff, newExp);
            }

            n2 = n2->next;
        } while (n2 != poly2);
        n1 = n1->next;
    } while (n1 != poly1);

    return result;
}

void printPolynomial(Node* head) {
    if (head == NULL) return;
    Node* n = head;
    do {
        printf("%dx^%d ", n->coeff, n->exp);
        if (n->next != head) printf("+ ");
        n = n->next;
    } while (n != head);
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        createNode(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        createNode(&poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    result = multiplyPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return EXIT_SUCCESS;
}
