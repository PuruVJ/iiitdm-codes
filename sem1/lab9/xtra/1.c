#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n;

  printf("Number of elements to be entered: ");
  scanf("%d", &n);

  // Ascending = 0, Descending = 1
  int order;

  // The array pointer
  int *numbers = (int *)malloc(sizeof(int) * n);

  printf("Enter the numbers: ");
  for (int i = 0; i < n; i++)
    scanf("%d", numbers + i);

  // Set the tentative order
  order = *(numbers) < *(numbers + n - 1) ? 0 : 1;

  for (int i = 0; i < n - 1; i++)
    if (order == 0)
    {
      if (*(numbers + i) <= *(numbers + i + 1))
        continue;
      else
      {
        printf("false");
        return;
      }
    }
    else
    {
      if (*(numbers + i) >= *(numbers + i + 1))
        continue;
      else
      {
        printf("false");
        return;
      }
    }

  printf("true");
}