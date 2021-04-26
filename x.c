#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  int r, n, i, j;

  printf("Enter the rank of the matrix : ");
  scanf("%d", &r);

  r = pow(r, 0.5);

  n = r * (r + 1) / 2;

  int *u = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    *(u + i) = rand() % 100;
  }

  printf("Elements on the upper triangle : ");

  for (i = 0; i < n; i++)
  {
    printf("  %d  ", *(u + i));
  }

  printf("\n");

  int *a = (int *)malloc(r * r * sizeof(int));

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      if (i <= j)
      {
        *(a + i * r + j) = *(u + i);

        i++;
      }
    }
  }

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      if (i >= j)
      {
        *(a + i * r + j) = *(a + i * r + j);
      }
    }
  }
  //Printing the matrix_array

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      printf("  %d  ", *(a + i * r + j));
    }
    printf("\n");
  }

  return 0;
}