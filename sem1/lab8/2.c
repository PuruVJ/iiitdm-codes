/**
 * Variance of matrix
 * Var = Sum((xi - mean) ^ 2) / n
 */
#include <stdio.h>

float calcMatrixMean(int m, int n, int matrix[][n])
{
  float sum = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      sum += matrix[i][j];

  return sum / (m * n);
}

float calcMatrixVariance(int m, int n, int matrix[][n])
{
  float mean = calcMatrixMean(m, n, matrix);

  float sum = 0;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      sum += (matrix[i][j] - mean) * (matrix[i][j] - mean);

  return sum / (m * n);
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
  printf("Variance is %f: \n", calcMatrixVariance(m, n, matrix));
}