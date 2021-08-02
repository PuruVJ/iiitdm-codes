#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _studentList {
  int rollNo;
  int marks;
  char grade;
  struct _studentList* next;
} StudentNode;

char deriveGrade(int marks) {
  char grade;

  if (marks >= 90)
    grade = 'A';
  else if (marks >= 80)
    grade = 'B';
  else if (marks >= 70)
    grade = 'C';
  else if (marks >= 60)
    grade = 'D';
  else if (marks >= 50)
    grade = 'E';
  else if (marks >= 35)
    grade = 'P';
  else
    grade = 'F';

  return grade;
}

void printList(StudentNode* head) {
  StudentNode* temp = head;

  while (temp != NULL) {
    printf(" %d %d marks", temp->rollNo, temp->marks);
    temp = temp->next;
  }
  printf("\n");
}

StudentNode* add(StudentNode* head, int rollNo, int marks, char grade) {
  StudentNode* ptr = (StudentNode*)malloc(sizeof(StudentNode));

  ptr->rollNo = rollNo;
  ptr->marks = marks;
  ptr->grade = grade;

  ptr->next = head;
  head = ptr;

  return head;
}

void printGradedStudentList(StudentNode* head) {
  // Start at the beginning
  StudentNode* temp = head;

  /**
   * The array of the different lists
   * Idx 0: A grade
   *     1: B grade
   *     2: C grade
   *     3: D grade
   *     4: E grade
   *     5: P grade
   *     6: F grade
   * And so on
   */
  StudentNode* gradeBasedArr[7];
  char gradesArr[7] = "ABCDEPF";

  // Initialise each list with its own head
  for (int i = 0; i < 7; i++) {
    StudentNode* gradeList = (StudentNode*)malloc(sizeof(StudentNode));
    gradeList = NULL;

    gradeBasedArr[i] = gradeList;
  }

  for (; temp != NULL;) {
    // Get the index of current' element's grade
    int idx;
    for (int i = 0; i < 7; i++)
      if (temp->grade == gradesArr[i]) idx = i;

    gradeBasedArr[idx] =
        add(gradeBasedArr[idx], temp->rollNo, temp->marks, temp->grade);

    // gradeBasedArr[idx];
    temp = temp->next;
  }

  for (int i = 0; i < 7; i++) {
    printf("Printing roll numbers who got %c grade: ", gradesArr[i]);
    printList(gradeBasedArr[i]);
  }
}

void main() {
  int n;

  printf("Enter value for n: ");
  scanf("%d", &n);

  srand(time(NULL));

  // Initial pointer
  StudentNode* head = (StudentNode*)malloc(sizeof(StudentNode));
  StudentNode* tail = (StudentNode*)malloc(sizeof(StudentNode));

  if (head == NULL || tail == NULL) {
    printf("Not enough memory to allocate \n");
    return;
  }

  // Start
  for (int i = 0; i < n; i++) {
    int rollNo = i + 1;
    int marks = rand() % 101;
    char grade = deriveGrade(marks);

    // Make the pointer for this one
    StudentNode* ptr = (StudentNode*)malloc(sizeof(StudentNode));

    if (ptr == NULL) {
      printf("Not enough memory to allocate for $%dth element: \n", i + 1);
      return;
    }

    // Set data
    ptr->rollNo = rollNo;
    ptr->marks = marks;
    ptr->grade = grade;

    // Set pointer link and stuff
    ptr->next = NULL;

    if (i == 0) {
      // First element. Make `head` and `tail` this.
      tail = head = ptr;
      head->next = tail;
      continue;
    }

    tail->next = ptr;
    tail = tail->next;
  }

  // Now split
  printGradedStudentList(head);
}