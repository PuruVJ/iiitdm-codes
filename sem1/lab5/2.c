#include <stdio.h>

int main()
{

  int number[30];

  int a, n;
  printf("Enter the value of n: \n");
  scanf("%d", &n);

  int i;
  printf("Enter the numbers: \n");
  for (i = 0; i < n; ++i)
  {
    scanf("%d", &number[i]);
  }

  // Measurements
  int swaps = 0, comparisons = 0;

  int j;
  // sorting begins...
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
    {
      if (number[i] < number[j])
      {
        a = number[i];
        number[i] = number[j];
        number[j] = a;

        // Increase swaps
        swaps++;
      }

      // Increase comparisons
      comparisons++;
    }

  printf("The numbers arranged in descending order are given below\n");

  for (i = 0; i < n; ++i)
  {
    printf(" %d ", number[i]);
  }

  printf("\n");

  printf("Comparisons: %d \n", comparisons);
  printf("Swaps: %d \n", swaps);

  return 0;
}