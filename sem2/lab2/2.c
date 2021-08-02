#include <stdlib.h>
#include <stdio.h>

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

  // Keep the count
  int count = 0;

  int start = 1;
  int end = (n - 1) - 1;

  while (start < end)
  {
    // Swap
    int temp = *(numbers + start);
    *(numbers + start) = *(numbers + end);
    *(numbers + end) = temp;

    start += 2;
    end -= 2;

    count++;
  }

  printf("\n");

  // Print this array
  printf("Array after swap: ");
  for (int i = 0; i < n; i++)
    printf("%d ", *(numbers + i));

  printf("\n");

  printf("Number of operations performed: %d\n", count);
}