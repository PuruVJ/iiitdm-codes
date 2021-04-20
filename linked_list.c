#include <stdio.h>
#include <malloc.h>

struct List
{
  int data;
  struct List *next;
};

void createList(struct List *node)
{
  printf("\n Creation of a Linked List\n\n");

  int i = 1;
  char ch;

  printf("\n Enter the value for %d node:", i);
  scanf("%d", &node->data);
  node->next = NULL;

  i++;

  printf("\n Press 'q' to Quit or any other key to continue:");
  scanf(" %c", &ch);

  while (ch != 'q')
  {
    struct List *ptr = NULL;
    ptr = (struct List *)malloc(sizeof(struct List));

    if (ptr == NULL)
    {
      printf("\n Out of Memory space");
      exit(0);
    }

    node->next = ptr;
    node = ptr;

    printf("\n Enter the value for %d node:", i);
    scanf("%d", &node->data);
    node->next = NULL;

    i++;

    printf("\n Press 'q' to Quit or any other key to continue:");
    scanf(" %c", &ch);
  }
}

void findMean(struct List *head)
{
  printf("\n The values in the List are: ");

  struct List *node = head;

  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }

  printf("\n");
}

int main()
{
  struct List *head = NULL;                          // Creation of the Head
  head = (struct List *)malloc(sizeof(struct List)); //Memory allocation to the head

  if (head == NULL) // Always check for memory space after malloc
  {
    printf("\n Out of Memory space");
    exit(0);
  }

  createList(head); //Create a Linked List
  findMean(head);   // Traverse a Linked List

  return 0;
}
