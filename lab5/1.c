#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// struct for linked list
typedef struct _List {
  int nodeIndex;
  float number;
  struct _List *next;
} List;

List *head;

void createList(int n) {
  List *node, *temp;

  head = (List *)malloc(sizeof(List));

  // Terminate if memory not allocated
  if (head == NULL) {
    printf("Unable to allocate memory.");
    exit(0);
  }

  head->number = rand() % 100;
  head->nodeIndex = 1;
  head->next = NULL;

  // Create n - 1 nodes and add to list
  temp = head;

  for (int i = 2; i <= n; i++) {
    node = (List *)malloc(sizeof(List));

    // Terminate if memory not allocated for newNode
    if (node == NULL) {
      printf("Unable to allocate memory.");
      break;
    }

    node->number = rand() % 100;
    node->nodeIndex = i;
    node->next = NULL;

    temp->next = node;
    temp = temp->next;
  }
}

void reverse(int factor) {
  List *temp = head;
  List *temp2, *prev, *next, *current;

  /** Number of elements in this set to be reversed */
  int batchSize;

  for (int i = 1; temp->next != NULL; i++) {
    batchSize = pow(factor, i);

    temp2 = temp->next;
    prev = temp2;

    if (prev->next == NULL) break;

    current = prev->next;
    next = current->next;

    for (int j = 1; j < batchSize; j++) {
      current->next = prev;
      prev = current;
      current = next;

      // Break out if current is empty now
      if (current == NULL) break;

      if (next != NULL) next = next->next;
    }

    temp2->next = current;

    temp->next = prev;
    temp = temp2;
  }
}

void printList() {
  List *temp = head;

  while (temp != NULL) {
    printf("node %d = %f\n", temp->nodeIndex, temp->number);
    temp = temp->next;
  }
}

void main() {
  int n;

  printf("Enter the total number of nodes: ");
  scanf("%d", &n);

  int factor;
  printf("Enter the factor of G.P.:-");
  scanf("%d", &factor);

  createList(n);

  printList();

  printf("---------------------\n After reordeing \n\n");

  reverse(factor);
  printList();
}