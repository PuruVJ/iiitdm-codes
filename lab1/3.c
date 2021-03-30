#include <stdio.h>
#include <string.h>

struct Student
{
  char name[100];
  int age;
  char rollNo[100];
  char address[100];
};

void main()
{
  struct Student studentInfo;

  // Name
  printf("Enter student name: ");
  scanf("%[^\n]%*c", studentInfo.name);

  // Age
  printf("Enter student age: ");
  scanf("%d", &(studentInfo.age));

  // Roll no
  printf("Enter student roll number: ");
  scanf("%[^\n]%*c", studentInfo.rollNo);

  // Address
  printf("Enter student address: ");
  scanf("%[^\n]%*c", studentInfo.address);

  // Now print this stuff
  printf("Student name: %s\n", studentInfo.name);
  printf("Student age: %d\n", studentInfo.age);
  printf("Student roll no.: %s\n", studentInfo.rollNo);
  printf("Student address: %s\n", studentInfo.address);
}