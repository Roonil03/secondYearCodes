#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int row;
    int col;
    int value;
} Element;

void fastTranspose(Element in[], int numEm, Element o[], int *numTransEm, int numRows, int numCols) {
    int rowTerms[MAX], startPos[MAX];
    int i, j;

    for (i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }

    for (i = 0; i < numEm; i++) {
        rowTerms[in[i].col]++;
    }

    startPos[0] = 0;
    for (i = 1; i < numCols; i++) {
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    }

    for (i = 0; i < numEm; i++) {
        int pos = startPos[in[i].col]++;
        o[pos].row = in[i].col;
        o[pos].col = in[i].row;
        o[pos].value = in[i].value;
    }

    *numTransEm = numEm;
}

void printSparseMatrix(Element arr[], int numEm) {
    for (int i = 0; i < numEm; i++) {
        printf("Row: %d, Col: %d, Value: %d\n", arr[i].row, arr[i].col, arr[i].value);
    }
}

int main() {
    Element in[MAX], o[MAX];
    int numEm, numTransEm;
    int numRows, numCols;

    printf("Enter the number of rows and columns in the sparse matrix: ");
    scanf("%d %d", &numRows, &numCols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numEm);

    printf("Enter the non-zero elements (row column value):\n");
    for (int i = 0; i < numEm; i++) {
        scanf("%d %d %d", &in[i].row, &in[i].col, &in[i].value);
    }

    fastTranspose(in, numEm, o, &numTransEm, numRows, numCols);

    printf("\nOriginal Sparse Matrix:\n");
    printSparseMatrix(in, numEm);

    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(o, numTransEm);

    return EXIT_SUCCESS;
}
