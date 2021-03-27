#include <stdio.h>
#include <stdlib.h>

void sum(int *numbers, int start, int n, int *sumVar)
{
  if (start >= n)
    return;

  *sumVar += *(numbers + start);

  sum(numbers, start + 1, n, sumVar);
}

void main()
{
  int n;

  printf("Enter number of elements to enter: ");
  scanf("%d", &n);

  int *numbers = (int *)malloc(sizeof(int) * n);

  int *sumVar;

  *sumVar = 0;

  printf("Enter elements in the array: ");
  for (int i = 0; i < n; i++)
    scanf("%d", numbers + i);

  sum(numbers, 0, n, sumVar);

  printf("%d", *sumVar);
}
