#include <stdio.h>
#include <math.h>

void main()
{
  int n;

  printf("Enter n: ");
  scanf("%d", &n);

  float sum = pow(n * (n + 1) / 2, 2);

  printf("%f\n", sum / pow(n, 3));
}