#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

void binaryMain() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return;
}
void selectionSort(int arr[], int n, int start) {
    if (start >= n - 1) {
        return;
    }

    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    int temp = arr[minIndex];
    arr[minIndex] = arr[start];
    arr[start] = temp;

    selectionSort(arr, n, start + 1);
}

void selectionMain() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n, 0);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return;
}

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + multiply(a, b - 1);
}

void multiplyMain() {
    int a = 5;
    int b = 3;

    int result = multiply(a, b);

    printf("Product of %d and %d is %d\n", a, b, result);

    return;
}

int main()
{
    int num=0;
    printf("Enter the choice you want to make: \n");
    printf("1. Binary Search");
    printf("\n2. Selection Sort");
    printf("\n3. Multiplying numbers\n");
    scanf("%d",&num);
    switch (num)
    {
        case 1:
        binaryMain();
        break;
        case 2:
        selectionMain();
        break;
        case 3:
        multiplyMain();
        break;
        default:
        break;
    }
    return EXIT_SUCCESS;
}