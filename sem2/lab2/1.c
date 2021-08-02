#include <stdio.h>
#include <stdlib.h>

void binarySearch(int n, int *numbers, int numToFind)
{
  int start = 0;
  int end = n - 1;

  // Count number of operations
  int count = 0;

  // Was the number found
  int numFound = 0;

  while (start <= end)
  {
    int middle = (start + end) / 2;

    count++;

    if (numToFind > *(numbers + middle))
    {
      start = middle + 1;
      continue;
    }

    if (numToFind < *(numbers + middle))
    {
      end = middle - 1;
      continue;
    }

    if (numToFind == *(numbers + middle))
    {
      numFound = 1;
      break;
    }
  }

  if (numFound)
    printf("Number found\n");
  else
    printf("Number not found\n");

  printf("Number of operations: %d\n", count);
}

void linearSearch(int n, int *numbers, int numToFind)
{
  int count = 0;

  int numFound = 0;

  for (int i = 0; i < n; i++)
  {
    count++;

    if (*(numbers + i) != numToFind)
      continue;

    // If number found, 👇
    numFound = 1;
    break;
  }

  if (numFound)
    printf("Number found\n");
  else
    printf("Number not found\n");

  printf("Number of operations: %d\n", count);
}

void main()
{
  int n;

  // Take input
  printf("Enter size of Array: ");
  scanf("%d", &n);

  int *numbers = (int *)malloc(n * sizeof(int));

  printf("Enter numbers in ascending order: ");
  for (int i = 0; i < n; i++)
    scanf("%d", numbers + i);

  // Number to search for
  int numToSearch;

  printf("Which number to search: ");
  scanf("%d", &numToSearch);

  printf("\n");

  printf("Applying linear Search: \n");
  linearSearch(n, numbers, numToSearch);

  printf("\n");

  printf("Applying binary Search: \n");
  binarySearch(n, numbers, numToSearch);
}