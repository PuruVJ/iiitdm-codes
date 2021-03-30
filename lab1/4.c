#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
  char *name;
  int age;
  char *rollNo;
  char *address;
};

void main()
{
  struct Student studentInfo;

  studentInfo.name = (char *)malloc(100 * sizeof(char));
  studentInfo.rollNo = (char *)malloc(100 * sizeof(char));
  studentInfo.address = (char *)malloc(100 * sizeof(char));

  // Name
  printf("Enter student name: ");
  scanf("%[^\n]%*c", studentInfo.name);

  // Age
  printf("Enter student age: ");
  scanf("%d", &(studentInfo.age));
  getchar();

  // Roll no
  printf("Enter student roll number: ");
  scanf("%[^\n]%*c", studentInfo.rollNo);

  // Address
  printf("Enter student address: ");
  scanf("%[^\n]%*c", studentInfo.address);

  // Now print this stuff
  printf("\n");
  printf("Student name: %s\n", (studentInfo.name));
  printf("Student age: %d\n", studentInfo.age);
  printf("Student roll no.: %s\n", (studentInfo.rollNo));
  printf("Student address: %s\n", (studentInfo.address));
}