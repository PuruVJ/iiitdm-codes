#include <stdio.h>

int main()
{
  int n1, n2;
  printf("Enter size of 1st array ");
  scanf("%d", &n1);

  printf("Enter size of 2nd array ");
  scanf("%d", &n2);

  int n;
  // Biggest size
  if (n1 > n2)
    n = n1;
  else
    n = n2;

  int arr1[n];
  int arr2[n];

  // Initialize the arrays
  for (int i = 0; i < n; i++)
  {
    arr1[i] = 0;
    arr2[i] = 0;
  }

  // Now input the values
  printf("Enter values of 1st array ");
  for (int i = 0; i < n1; i++)
    scanf("%d", &arr1[i]);

  printf("Enter values of 2nd array ");
  for (int i = 0; i < n2; i++)
    scanf("%d", &arr2[i]);

  // Sum those arrays
  for (int i = 0; i < n; i++)
    printf("%d ", arr1[i] + arr2[i]);

  return 0;
}