/**
 * Sum of all elements at intersection of odd columns and even rows
 */

#include <stdio.h>

int sumMatrixSpecialElements(int m, int n, int matrix[][n])
{
  int sum = 0;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (i % 2 == 1 && j % 2 == 0)
        sum += matrix[i][j];

  return sum;
}

void main()
{
  int m, n;

  printf("Enter number of rows and columns, separated by space: ");
  scanf("%d %d", &m, &n);

  int matrix[m][n];

  printf("Enter %d numbers: \n", m * n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &matrix[i][j]);

  // Now print the sum
  printf("Sum is %d: \n", sumMatrixSpecialElements(m, n, matrix));
}