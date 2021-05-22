#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// struct for linked list
typedef struct _list {
  int nodeIndex;
  long long int data;
  struct _list *next, *prev;
} List;

List *head, *end;

// function for reading elements in linked list
void createList(int n) {
  struct _list *node, *temp, *temp1;

  head = (struct _list *)malloc(sizeof(struct _list));

  // Terminate if memory not allocated
  if (head == NULL) {
    printf("Unable to allocate memory.");
    exit(0);
  }

  head->data = 1;
  head->nodeIndex = 1;

  head->next = NULL;
  head->prev = NULL;

  end = head;

  // Create n - 1 nodes and add to list
  temp = temp1 = head;

  for (int i = 2; i <= n; i++) {
    node = (List *)malloc(sizeof(List));

    // Terminate if memory not allocated for newNode
    if (node == NULL) {
      printf("Unable to allocate memory.");
      break;
    }

    if (i == 2) {
      node->data = 1;
      node->nodeIndex = i;

      node->next = NULL;
      node->prev = temp;

      end = node;

      temp->next = node;
      temp = temp->next;
    } else {
      // nth term = (n-1)th term +(n-2)th term
      node->data = temp->data + temp1->data;
      node->nodeIndex = i;

      node->next = NULL;
      node->prev = temp;

      end = node;

      temp->next = node;
      temp = temp->next;
      temp1 = temp1->next;
    }
  }
}

// function for delering node
void deleteList(int factor) {
  List *temp1, *temp = head;

  int i, j, gpIndex;
  i = j = gpIndex = 1;

  for (; temp != NULL; i++) {
    if (i / gpIndex == 1) {
      if (i == 1 || i == 2) {
        head = head->next;

        head->prev = NULL;

        free(temp);

        temp = head;
      } else if (temp->next == NULL) {
        end = temp->prev;

        temp->prev->next = NULL;

        free(temp);
      } else {
        temp1 = temp;
        temp = temp->next;

        temp1->prev->next = temp1->next;
        temp1->next->prev = temp1->prev;

        free(temp1);
      }

      gpIndex = pow(factor, j);

      j++;
    } else {
      temp = temp->next;
    }
  }
}

void printList() {
  List *temp = head;

  while (temp != NULL) {
    printf("%lld ", temp->data);
    temp = temp->next;
  }
}

void main() {
  int n;
  printf("Enter the total number of nodes: ");
  scanf("%d", &n);

  createList(n);

  int factor;
  printf("Enter the factor of G.P.:-");
  scanf("%d", &factor);

  printList();
  printf("\n-----------------------------------\n");

  deleteList(factor);
  printList();

  printf("\n");
}