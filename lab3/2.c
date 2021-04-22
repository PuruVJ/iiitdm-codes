#include <stdlib.h>
#include <stdio.h>

void printMatrix(int rank, int *matrix)
{
  // Print out the matrix
  for (int i = 0; i < rank; i++)
  {
    for (int j = 0; j < rank; j++)
    {
      int currentElement = *(matrix + i * rank + j);

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
  int rank;

  printf("Enter rank of matrix: ");
  scanf("%d", &rank);

  int *matrix = (int *)malloc(rank * rank * sizeof(int));

  for (int i = 0; i < rank; i++)
    for (int j = i; j < rank; j++)
    {
      int num = rand() % 100;
      *(matrix + i * rank + j) = num;
      *(matrix + j * rank + i) = num;
    }

  printf("\n\nGenerated symmetric matrix: \n\n");
  printMatrix(rank, matrix);
}