#include <stdlib.h>
#include <stdio.h>

void main()
{
  int n;

  printf("Enter number of elements to be entered: ");
  scanf("%d", &n);

  int *numbers = (int *)malloc(n * sizeof(int));

  printf("Enter the numbers: \n");
  for (int i = 0; i < n; i++)
    scanf("%d", numbers + i);

  // Declare the 2 vars
  int start = 0, end = n - 1;

  // Now lets begin
  while (start < end)
  {
    if (*(numbers + start) % 2 == 1)
    {
      // Swap them
      int temp = *(numbers + start);
      *(numbers + start) = *(numbers + end);
      *(numbers + end) = temp;

      end--;
      continue;
    }

    start++;
  }

  for (int i = 0; i < n; i++)
    printf("%d ", *(numbers + i));

  printf("\n");
}