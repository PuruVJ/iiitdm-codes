#include <stdio.h>

int calcProduct(int arr[], int n)
{
  if (n == 1)
    return arr[0];

  return arr[n - 1] * calcProduct(arr, n - 1);
}

void main()
{
  int n;

  printf("How many numbers to be entered: ");
  scanf("%d", &n);

  int numbers[n];

  printf("Enter the numbers, separated by spaces: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &numbers[i]);

  printf("Product of these numbers: %d\n", calcProduct(numbers, n));
}