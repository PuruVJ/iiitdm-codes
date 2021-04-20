#include <stdio.h>
#include <stdlib.h>

void encryptMatrix(int numRows, int numColumns, int *matrix)
{
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numColumns; j++)
      *(matrix + i * numColumns + j) += (i == 0 || j == 0) ? i + 1 : -((i + 1) + (j + 1));
}

void decryptMatrix(int numRows, int numColumns, int *matrix)
{
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numColumns; j++)
      *(matrix + i * numColumns + j) -= (i == 0 || j == 0) ? i + 1 : -((i + 1) + (j + 1));
}

void printMatrix(int numRows, int numCols, int *matrix)
{
  // Print out the matrix
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
      printf("%d ", *(matrix + i * numCols + j));
    printf("\n");
  }
}

void main()
{
  int numRows, numColumns;

  // Input numRows and numColumns
  printf("Enter number of rows and columns, separated by a space: ");
  scanf("%d %d", &numRows, &numColumns);

  int *matrix = (int *)malloc(numRows * numColumns * sizeof(int));

  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numColumns; j++)
      *(matrix + i * numColumns + j) = rand() % 100;

  printf("\n\nInitial matrix: \n");
  printMatrix(numRows, numColumns, matrix);

  encryptMatrix(numRows, numColumns, matrix);
  printf("\n\nEncrypted matrix: \n");
  printMatrix(numRows, numColumns, matrix);

    decryptMatrix(numRows, numColumns, matrix);
  printf("\n\nDecrypted matrix: \n");
  printMatrix(numRows, numColumns, matrix);
}