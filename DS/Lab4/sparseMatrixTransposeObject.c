#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

void printMatrix(Term matrix[], int numTerms);
void transposeMatrix(Term in[], Term out[], int numTerms);

int main() {
    Term matrix[MAX];
    Term transposed[MAX];
    int numTerms, i;

    printf("Enter the number of non-zero terms: ");
    scanf("%d", &numTerms);

    printf("Enter the terms in the format (row column value):\n");
    for (i = 0; i < numTerms; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }

    transposeMatrix(matrix, transposed, numTerms);

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, numTerms);

    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, numTerms);

    return EXIT_SUCCESS;
}

void printMatrix(Term matrix[], int numTerms) {
    for (int i = 0; i < numTerms; i++) {
        printf("Row: %d, Col: %d, Value: %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

void transposeMatrix(Term in[], Term out[], int numTerms) {
    for (int i = 0; i < numTerms; i++) {
        out[i].row = in[i].col;
        out[i].col = in[i].row;
        out[i].value = in[i].value;
    }
}
