#include <stdio.h>
#include <stdlib.h>

void main()
{
  // Dimensions of matrix
  int numRows, numColumns;

  printf("Enter number of rows and columns: ");
  scanf("%d %d", &numRows, &numColumns);

  // Define matrix
  int *matrix = (int *)malloc(sizeof(int) * numRows * numColumns);

  // Take input
  printf("Enter the matrix: ");
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numColumns; j++)
      scanf("%d", matrix + (i * numRows) + j);

  // Take the searched for number
  int searchedEl;

  printf("Enter the element to be searched: ");
  scanf("%d", &searchedEl);

  // This is basically binary search
  // Flatten the matrix for code purposes, and we're done for the day

  // Current row index, current column index
  int start = 0;
  int end = ((numRows - 1) * numRows) + numColumns - 1;

  for (int i = 0; (start <= end) && i < 100; i++)
  {

    int middle = (start + end) / 2;

    int middleVal = *(matrix + middle);

    if (middleVal > searchedEl)
    {
      // Make middle the higher
      end = middle - 1;
      continue;
    }

    if (middleVal < searchedEl)
    {
      start = middle + 1;
      continue;
    }

    printf("true\n");
    return;
  }

  printf("false\n");
}