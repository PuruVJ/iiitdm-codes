#include <stdio.h>
#include <stdlib.h>

/**
 * Deletes array items by moving items towards the left
 */
int deleteItem(int n, int *numbers, int index)
{
  int count = 0;
  for (int i = index; i < n - index; i++)
  {
    *(numbers + i) = *(numbers + i + 1);
    count++;
  }

  return count;
}

/**
 * Utility function to print the array given the pointer
 */
void printArr(int n, int *numbers)
{
  for (int i = 0; i < n; i++)
    printf("%d ", *(numbers + i));
}

void main()
{
  // Array length from user
  int n;

  printf("Enter number of items: ");
  scanf("%d", &n);

  // Now do the random stuff
  int *numbers = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
    *(numbers + i) = rand();

  // Print this array
  printf("Array generated: ");
  for (int i = 0; i < n; i++)
    printf("%d ", *(numbers + i));

  printf("\n\n");

  int gpIndex = 1;

  // Which iterations it is
  int count = 0;
  int operations = 0;

  while (gpIndex < n)
  {
    count++;
    operations++;

    operations += deleteItem(n - count, numbers, gpIndex);

    printf("Iteration #%d: ", count);
    printArr(n - count, numbers);
    printf("\n");

    gpIndex *= 2;
  }

  printf("\n\n");

  printf("Total number of operations: %d\n", operations);
}