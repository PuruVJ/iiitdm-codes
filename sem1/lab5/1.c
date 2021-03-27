#include <stdio.h>

int main()
{
  // Input var
  int n;

  printf("Enter number of integers to be entered: ");
  scanf("%d", &n);

  // Input the numbers
  printf("Enter the integers: \n");
  int arr[n], i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Enter x
  int x;
  printf("Enter the sum(x) to be checked: ");
  scanf("%d", &x);

  int pairFound = 0;

  // Now check
  int j, k;
  for (j = 0; j < n; j++)
    for (k = j + 1; k < n; k++)
      if (arr[j] + arr[k] == x)
      {
        // Found a pair
        printf("(%d, %d) \n", arr[j], arr[k]);
        pairFound = 1;
      }

  if (!pairFound)
  {
    printf("No pair found");
  }

  return 0;
}