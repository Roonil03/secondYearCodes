#include <stdio.h>

#define MAX 100 

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int isMagicSquare(int matrix[MAX][MAX], int n) {
    int sum = 0;
    int tempSum;

    for (int j = 0; j < n; j++) {
        sum += matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        tempSum = 0;
        for (int j = 0; j < n; j++) {
            tempSum += matrix[i][j];
        }
        if (tempSum != sum) {
            return 0; 
        }
    }

    for (int j = 0; j < n; j++) {
        tempSum = 0;
        for (int i = 0; i < n; i++) {
            tempSum += matrix[i][j];
        }
        if (tempSum != sum) {
            return 0;
        }
    }

    tempSum = 0;
    for (int i = 0; i < n; i++) {
        tempSum += matrix[i][i];
    }
    if (tempSum != sum) {
        return 0; 
    }

    tempSum = 0;
    for (int i = 0; i < n; i++) {
        tempSum += matrix[i][n - i - 1];
    }
    if (tempSum != sum) {
        return 0; 
    }

    return 1; 
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int i, j;

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA != rowsB || colsA != colsB) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    readMatrix(A, rowsA, colsA);

    printf("Enter elements of Matrix B:\n");
    readMatrix(B, rowsB, colsB);

    addMatrices(A, B, C, rowsA, colsA);
    printf("Matrix A + Matrix B:\n");
    printMatrix(C, rowsA, colsA);

    printf("Enter the number of columns for Matrix B for multiplication: ");
    scanf("%d", &colsB);

    if (colsA != rowsB) {
        printf("Error: Number of columns of A must be equal to number of rows of B for multiplication.\n");
        return 1;
    }

    printf("Enter elements of Matrix B:\n");
    readMatrix(B, rowsB, colsB);

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);
    printf("Matrix A * Matrix B:\n");
    printMatrix(C, rowsA, colsB);

    int n;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Matrix size exceeds the maximum allowed size.\n");
        return 1;
    }

    printf("Enter elements of the square matrix:\n");
    readMatrix(A, n, n);

    if (isMagicSquare(A, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is not a magic square.\n");
    }

    return 0;
}
