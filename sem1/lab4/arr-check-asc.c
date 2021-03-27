#include <stdio.h>

int main()
{
  // Input vars
  int n, arr[100];

  // Number of inputs to be taken
  printf("Number of integers to entered (not more than 100): ");
  scanf("%d", &n);

  // Not more than 100
  if (n > 100)
  {
    printf("Number should not be more than 100");
    return 0;
  }

  int i;
  for (i = 0; i < n; i++)
  {
    printf("Enter %dth integer: ", i + 1);
    scanf("%d", &arr[i]);
  }

  // Now do the checking
  for (i = 0; i < n - 1; i++)
  {
    if (arr[i + 1] < arr[i])
    {
      printf("The numbers entered aren't in ascending order \n");
      return 0;
    }
  }

  printf("The numbers entered are in ascending order \n");

  return 0;
}