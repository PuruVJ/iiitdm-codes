#include <stdio.h>
#include <stdlib.h>

typedef struct fibList {
  int number;
  struct fibList *next;
} FibList;

void main() {
  int n;

  printf("Enter value for n: ");
  scanf("%d", &n);

  // For fibonacci
  int first = 0;
  int second = 1;

  // Summations
  int evenSum = 0;
  int oddSum = 0;

  FibList *head = (FibList *)malloc(sizeof(FibList));

  // Terminate if memory not allocated
  if (head == NULL) {
    printf("Unable to allocate memory.");
    exit(0);
  }

  head->number = second;
  head->next = NULL;

  for (int i = 0; i < n; i++) {
    if (head->number % 2)
      oddSum += head->number;
    else
      evenSum += head->number;

    FibList *temp = (FibList *)malloc(sizeof(FibList));

    /* If memory is not allocated for newNode */
    if (temp == NULL) {
      printf("Unable to allocate memory.");
      return;
    }

    // Swap fibonacci
    int tempFib = second;
    second = first + second;
    first = tempFib;

    temp->number = second;
    temp->next = NULL;

    head->next = temp;
    head = head->next;
  }

  FibList *current = head;
  FibList *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  printf("Even sum: %d\n", evenSum);
  printf("Odd sum: %d\n", oddSum);
}