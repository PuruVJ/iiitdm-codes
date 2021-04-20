#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct List
{
  int number;
  struct List *next;
};

void createList(struct List *node)
{
  int i = 1;
  char stopChar;

  printf("\n Enter value for node #%d:", i);
  scanf("%d", &node->number);
  node->next = NULL;

  i++;

  printf("\n Press 'q' to Quit or any other key to continue:");
  scanf("%c", &stopChar);

  while (stopChar != 'q')
  {
    struct List *numberList = NULL;
    numberList = (struct List *)malloc(sizeof(struct List));

    if (numberList == NULL)
    {
      printf("\n Out of Memory space");
      return;
    }

    node->next = numberList;
    node = numberList;

    printf("\n Enter value for node #%d:", i);
    scanf("%d", &node->number);
    node->next = NULL;

    i++;

    printf("\n Press 'q' to Quit or any other key to continue:");
    scanf(" %c", &stopChar);
  }
}

float findMean(struct List *head)
{
  struct List *node = head;
  float sum = 0;
  int len = 0;

  while (node != NULL)
  {
    sum += node->number;
    len++;

    node = node->next;
  }

  printf("\nMean is %f", sum / len);

  return sum / len;
}

void findStdDev(struct List *head, float mean)
{
  struct List *node = head;
  float sum = 0;
  int len = 0;

  while (node != NULL)
  {
    sum += pow(node->number - mean, 2);
    len++;

    node = node->next;
  }

  printf("Standard Deviation is %f", sqrt(sum / len));
}

void main()
{
  struct List *head = NULL;
  head = (struct List *)malloc(sizeof(struct List));

  if (head == NULL) // Always check for memory space after malloc
  {
    printf("\n Out of Memory space");
    return;
  }

  createList(head);

  float mean = findMean(head);
  printf("\n\n");
  findStdDev(head, mean);
  printf("\n");

  return;
}
