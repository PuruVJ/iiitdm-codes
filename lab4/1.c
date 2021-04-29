#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _List {
  char character;
  struct _List *next;
} List;

int arrIncludes(int val, int arr[], int n) {
  for (int i = 0; i < n; i++)
    if (arr[i] == val) return 1;

  return 0;
}

void deleteNode(List **node, int index) {
  // Store head node
  List *temp = *node;

  // If head needs to be removed
  if (index == 0) {  // Change head
    *node = temp->next;

    // free old head
    free(temp);
    return;
  }

  // Find previous node of the node to be deleted
  for (int i = 0; temp != NULL && i < index - 1; i++) temp = temp->next;

  // If position is more than number of nodes
  if (temp == NULL || temp->next == NULL) return;

  // Node temp->next is the node to be deleted
  // Store pointer to the next of node to be deleted
  List *next = temp->next->next;

  // Unlink the node from linked list
  // Free memory
  free(temp->next);

  // Unlink the deleted node from list
  temp->next = next;
}

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

void printList(List *node, int n) {
  List *temp = node;

  while (temp != NULL) {
    printf("%c", temp->character);
    temp = temp->next;
  }
  printf("\n\n");
}

void pruneList(List *node, int n) {
  int accountedForChars[26];
  int arrIndex = 0;

  // Fill array with -1 values
  for (int i = 0; i < 26; i++) accountedForChars[i] = -1;

  List *temp = node;

  while (temp != NULL) {
    if (arrIncludes(temp->character, accountedForChars, 26))
      deleteNode(&node, temp->character);
    else {
      accountedForChars[arrIndex] = temp->character;
      arrIndex++;
    }

    temp = temp->next;

    node->next = temp;
    node = node->next;
  }
}

void main() {
  int n;

  printf("Enter value for n: ");
  scanf("%d", &n);

  List *list = (List *)malloc(sizeof(List));

  // Terminate if memory not allocated
  if (list == NULL) {
    printf("Unable to allocate memory.");
    exit(0);
  }

  srand(time(NULL));

  createList(list, n);

  printf("Generated list: \n");
  printList(list, n);

  printf("\n\n");

  printf("Pruned list: \n");
  pruneList(list, n);
}