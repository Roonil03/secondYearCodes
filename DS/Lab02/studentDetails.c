#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 51
#define PEOPLE 4  

typedef struct Student {
  char name[MAX];
  int roll;
  char grade;
} Student;

void read(Student*);
void display(Student);
void sort(Student*);  

int main() {
  Student s[PEOPLE];
  int i;

  for (i = 0; i < PEOPLE; i++) {
    Student* p = &s[i];
    read(p);
  }

  for (i = 0; i < PEOPLE; i++) {
    display(s[i]);
  }
  printf("\nSorting Array... \n");

  sort(s);  

  for (i = 0; i < PEOPLE; i++) {
    display(s[i]);
  }

  return EXIT_SUCCESS;
}

void read(Student* pint) {
  printf("Enter the name of student: ");
  scanf("%s", &pint->name);
  printf("Enter the roll number: ");
  scanf("%d", &pint->roll);
  printf("Enter the grade of the student: ");
  scanf(" %c", &pint->grade); 
}

void display(Student dis) {
  printf("Name: %s", dis.name);
  printf("\nRoll Number: %d", dis.roll);
  printf("\nGrade: %c\n\n", dis.grade);
}

void sort(Student* arr) {
  for (int i = 0; i < PEOPLE - 1; i++) {
    for (int j = 0; j < PEOPLE - i - 1; j++) {
      if (arr[j].roll > arr[j + 1].roll) {
        Student temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}