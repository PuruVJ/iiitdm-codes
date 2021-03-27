#include <stdio.h>

int main()
{
  // Input vars
  int n, arr[100];

  // Sum of odd nos
  int sumOfOddNums = 0;

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

  // Now sum up the odd numbers
  for (i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 1)
    {
      // Odd
      sumOfOddNums += arr[i];
    }
  }

  printf("Sum of odd numbers entered: %d \n", sumOfOddNums);

  return 0;
}