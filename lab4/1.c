#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _List {
  char character;
  struct _List *next;
} List;

void createList(List *node, int n) {
  node->character = (char)(65 + rand() % 26);
  node->next = NULL;

  for (int i = 1; i < n; i++) {
    List *temp = (List *)malloc(sizeof(List));

    /* If memory is not allocated for newNode */
    if (temp == NULL) {
      printf("Unable to allocate memory.");
      break;
    }

    temp->character = (char)(65 + rand() % 26);
    temp->next = NULL;

    node->next = temp;
    node = node->next;
  }
}

void printList(List *node) {
  List *temp = node;

  while (temp != NULL) {
    printf("%c", temp->character);
    temp = temp->next;
  }
  printf("\n\n");
}

/* Bubble sort the given linked list */
/* function to swap data of two nodes a and b*/
void swap(List *a, List *b) {
  int temp = a->character;
  a->character = b->character;
  b->character = temp;
}

void bubbleSort(List *head) {
  int swapped, i;
  List *ptr1;
  List *lptr = NULL;

  /* Checking for empty list */
  if (head == NULL) return;

  do {
    swapped = 0;
    ptr1 = head;

    while (ptr1->next != lptr) {
      if (ptr1->character > ptr1->next->character) {
        swap(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

void pruneList(List *head) {
  List *current = head;
  List *next_next;

  if (current == NULL) return;

  while (current->next != NULL) {
    /* Compare current node with its next */
    if (current->character == current->next->character) {
      next_next = current->next->next;

      free(current->next);

      current->next = next_next;
    } else {
      current = current->next;
    }
  }
}

void main() {
  int n;

  printf("Enter value for n: ");
  scanf("%d", &n);

  List *head = (List *)malloc(sizeof(List));

  // Terminate if memory not allocated
  if (head == NULL) {
    printf("Unable to allocate memory.");
    exit(0);
  }

  srand(time(NULL));

  createList(head, n);

  // Sort the items
  bubbleSort(head);

  printf("Generated list: \n");
  printList(head);

  printf("\n\n");

  pruneList(head);
  printf("Pruned list: \n");
  printList(head);
}