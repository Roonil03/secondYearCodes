#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char name[50];
    int roll;
    char grade;
    char branch[50];
} Student;

void writeToFile(Student students[], int n) {
    FILE *fp = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %c %s\n", students[i].name, students[i].roll, students[i].grade, students[i].branch);
    }
    fclose(fp);
}

void readFromFile(Student students[], int *n) {
    FILE *fp = fopen("students.txt", "r");
    *n = 0;
    while (fscanf(fp, "%s %d %c %s", students[*n].name, &students[*n].roll, &students[*n].grade, students[*n].branch) == 4) {
        (*n)++;
    }
    fclose(fp);
}

void createBranchFiles(Student students[], int n) {
    FILE *fp;
    for (int i = 0; i < n; i++) {
        char filename[100];
        sprintf(filename, "%s.txt", students[i].branch);
        fp = fopen(filename, "a");
        fprintf(fp, "%s %d %c\n", students[i].name, students[i].roll, students[i].grade);
        fclose(fp);
    }
}

int main() {
    Student students[100];
    int n;

    writeToFile(students, 5);

    readFromFile(students, &n);

    createBranchFiles(students, n);

    return EXIT_SUCCESS;
}
