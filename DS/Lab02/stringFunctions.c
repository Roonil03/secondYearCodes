#include <stdio.h>
#include <stdlib.h>
#define MAX 51

int stringLength(char[]);
char* stringConcat(char[], char[]);
int stringCompar(char[], char[]);
char* stringInsert(char[], char[], int);
char* stringDelete(char[], char[]);

char h[MAX * 2];
char del[MAX * 2];

int main() {
    printf("Enter the first string: ");
    char str[MAX];
    scanf("%s", str);
    printf("The length of the string is: %d\n", stringLength(str));

    printf("Enter the second string: ");
    char s2[MAX];
    scanf("%s", s2);
    printf("The concatenated string is: %s\n", stringConcat(str, s2));

    printf("Enter a string to compare with the original: ");
    char s3[MAX];
    scanf("%s", s3);
    printf("Comparing the strings \"%s\" and \"%s\", we get: %d\n", str, s3, stringCompar(str, s3));

    printf("Enter the string to insert: ");
    char s4[MAX];
    scanf("%s", s4);
    int poin;
    printf("Enter the index to insert at: ");
    scanf("%d", &poin);
    printf("Inserting the string, we get: %s\n", stringInsert(str, s4, poin));

    printf("Enter the string to delete: ");
    char s5[MAX];
    scanf("%s", s5);
    printf("The deleted string is: %s\n", stringDelete(str, s5));

    return EXIT_SUCCESS;
}

int stringLength(char str[]) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

char* stringConcat(char f1[], char f2[]) {
    int i = 0;
    int j = 0;

    while (f1[i] != '\0') {
        h[i] = f1[i];
        i++;
    }

    while (f2[j] != '\0') {
        h[i] = f2[j];
        i++;
        j++;
    }
    h[i] = '\0';

    return h;
}

int stringCompar(char c1[], char c2[]) {
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0' && c1[i] == c2[i]) {
        i++;
    }
    return c1[i] - c2[i];
}

char* stringInsert(char m[], char in[], int num) {
    int i, j;
    int mLength = stringLength(m);
    int inLength = stringLength(in);

    for (i = 0; i < num && i < mLength; i++) {
        h[i] = m[i];
    }

    for (j = 0; j < inLength; j++, i++) {
        h[i] = in[j];
    }

    while (i < mLength + inLength) {
        h[i] = m[i - inLength];
        i++;
    }
    h[i] = '\0';

    return h;
}

char* stringDelete(char d1[], char d2[]) {
    int deleteLength = stringLength(d2);
    int fullLength = stringLength(d1);
    int i, j, k;

    for (i = 0; i <= fullLength - deleteLength; i++) {
        for (j = 0, k = i; j < deleteLength; j++, k++) {
            if (d1[k] != d2[j]) {
                break;
            }
        }

        if (j == deleteLength) {
            for (k = i; k < fullLength - deleteLength; k++) {
                d1[k] = d1[k + deleteLength];
            }
            d1[k] = '\0';
            break;
        }
    }

    int len = stringLength(d1);
    for (i = 0; i <= len; i++) {
        del[i] = d1[i];
    }

    return del;
}