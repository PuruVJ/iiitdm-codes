/*
Create a Linked List of N students. Each student node will have roll_no,
percentage of marks, and the corresponding grade. The roll_no will vary from 1
to N. Percentage of marks will be taken as a random input. The grading system is
as given below.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int rollno = 1, c, a, b, node_number = 1, N;

// defining a structure
struct student_data {
  int roll_no;
  int percentage;
  char grade;
  struct student_data *next_element_address;
};
// grade( ) takes input percentage and returns its grade in char
char grade(int percentage) {
  if (percentage >= 90)
    return 'A';
  else if (percentage >= 80)
    return 'B';
  else if (percentage >= 70)
    return 'C';
  else if (percentage >= 60)
    return 'D';
  else if (percentage >= 50)
    return 'E';
  else if (percentage >= 35)
    return 'P';
  else {
    return 'F';
  }
}
// add_ function takes head and inserts a node at begining ah returns the
// address of new head

struct student_data *add_(struct student_data *head, int roll_no,
                          int percentage, char grade) {
  struct student_data *ptr =
      (struct student_data *)malloc(sizeof(struct student_data));
  ptr->roll_no = roll_no;
  ptr->percentage = percentage;
  ptr->grade = grade;
  ptr->next_element_address = NULL;

  ptr->next_element_address = head;
  head = ptr;
  return head;
}
// function to print the elements of the linked list

void printList(struct student_data *head) {
  struct student_data *node = head;
  while (node != NULL) {
    printf(" roll number  = %d ", node->roll_no);
    printf(" percentage   = %d ", node->percentage);
    printf(" grade = %c \n", node->grade);

    node = node->next_element_address;
  }
}
int main() {
  srand(time(NULL));
  struct student_data *first_node =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *A =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *B =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *C =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *D =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *E =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *P =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *F =
      (struct student_data *)malloc(sizeof(struct student_data));
  struct student_data *grade_sheet[] = {A, B, C, D, E, P, F};
  A = NULL;
  B = NULL;
  C = NULL;
  D = NULL;
  E = NULL;
  P = NULL;
  F = NULL;
  printf("\nenter the number of elements u wanna enter ");
  scanf("%d", &N);
  struct student_data *node = first_node;
  node->roll_no = rollno;
  node->percentage = rand() % 100;
  node->grade = grade(node->percentage);
  switch (node->grade) {
    case 'A':
      A = add_(A, node->roll_no, node->percentage, node->grade);
      break;
    case 'B':
      B = add_(B, node->roll_no, node->percentage, node->grade);
      break;
    case 'C':
      C = add_(C, node->roll_no, node->percentage, node->grade);
      break;
    case 'D':
      D = add_(D, node->roll_no, node->percentage, node->grade);
      break;
    case 'E':
      E = add_(E, node->roll_no, node->percentage, node->grade);
      break;
    case 'P':
      P = add_(P, node->roll_no, node->percentage, node->grade);
      break;
    case 'F':
      F = add_(F, node->roll_no, node->percentage, node->grade);
      break;
  }
  rollno += 1;  // making first element as 1
  node->next_element_address = NULL;
  for (node_number = 2; node_number <= N; node_number++) {
    struct student_data *dummy =
        (struct student_data *)malloc(sizeof(struct student_data));
    node->next_element_address =
        dummy;  // making the next_element_address of previous node as the
                // address of data of next node
    node = dummy;  // changing head position to next element
    node->percentage = rand() % 100;
    node->grade = grade(node->percentage);
    node->roll_no = rollno;
    switch (node->grade) {
      case 'A':
        A = add_(A, node->roll_no, node->percentage, node->grade);
        break;
      case 'B':
        B = add_(B, node->roll_no, node->percentage, node->grade);
        break;
      case 'C':
        C = add_(C, node->roll_no, node->percentage, node->grade);
        break;
      case 'D':
        D = add_(D, node->roll_no, node->percentage, node->grade);
        break;
      case 'E':
        E = add_(E, node->roll_no, node->percentage, node->grade);
        break;
      case 'P':
        P = add_(P, node->roll_no, node->percentage, node->grade);
        break;
      case 'F':
        F = add_(F, node->roll_no, node->percentage, node->grade);
        break;
    }
    rollno += 1;
    node->next_element_address =
        NULL;  // as this element is last now , its link will be null
  }

  printf(
      "\n---------------------------the original linked list of student data "
      "is------------------------------------\n");
  printList(first_node);
  printf("\n=================A============\n");
  printList(A);
  printf("\n=================b============\n");
  printList(B);
  printf("\n=================c============\n");
  printList(C);
  printf("\n=================d============\n");
  printList(D);
  printf("\n=================e============\n");
  printList(E);
  printf("\n=================p============\n");
  printList(P);
  printf("\n=================f============\n");
  printList(F);
}