#include <stdio.h>

void printArr(int arr[], int n)
{
  printf("%d\n", arr[n - 1]);

  if (n == 1)
    return;

  printArr(arr, n - 1);
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

  printArr(numbers, n);
}