#include <stdio.h>

int main()
{
  // Number of elements in the array
  int n;
  int sum = 0;

  printf("Enter value of n ");
  scanf("%d", &n);

  // Array
  int arr[n];

  printf("Enter the numbers ");

  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for (i = 0; i < n; i++)
    if (arr[i] % 3 == 0 || arr[i] % 7 == 0)
      sum += arr[i];

  printf("%d", sum);
}