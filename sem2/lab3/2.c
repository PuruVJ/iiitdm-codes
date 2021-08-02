#include <stdlib.h>
#include <stdio.h>

void printMatrix(int order, int *matrix)
{
  // Print out the matrix
  for (int i = 0; i < order; i++)
  {
    for (int j = 0; j < order; j++)
    {
      int currentElement = *(matrix + i * order + j);

      if (currentElement < 10)
        printf("0%d ", currentElement);
      else
        printf("%d ", currentElement);
    }
    printf("\n");
  }
}

void main()
{
  int order;

  printf("Enter order of matrix: ");
  scanf("%d", &order);

  int *matrix = (int *)malloc(order * order * sizeof(int));

  for (int i = 0; i < order; i++)
    for (int j = i; j < order; j++)
    {
      int num = rand() % 100;
      *(matrix + i * order + j) = num;
      *(matrix + j * order + i) = num;
    }

  printf("\n\nGenerated symmetric matrix: \n\n");
  printMatrix(order, matrix);
}