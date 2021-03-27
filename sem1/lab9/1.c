#include <stdio.h>
#include <stdlib.h>

void sort(int n, int *arr)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (*(arr + j) > *(arr + j + 1))
      {
        int temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
      }
}

void main()
{
  int *pNumbers = (int *)malloc(sizeof(int) * 100);
  int n;

  printf("How many integers to be entered: ");
  scanf("%d", &n);

  printf("Enter the numbers: ");
  for (int i = 0; i < n; i++)
    scanf("%d", pNumbers + i);

  sort(n, pNumbers);

  for (int i = 0; i < n; i++)
    printf("%d ", *(pNumbers + i));

  printf("\n");
}