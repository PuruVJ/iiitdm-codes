#include <stdio.h>
#include <math.h>

int factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int main()
{
  int x, n;

  printf("Enter x ");
  scanf("%d", &x);

  printf("Enter n ");
  scanf("%d", &n);

  float val = 0;
  for (int i = 0; i <= n; i++)
    val += 1.0 * pow(-1, i) * pow(x, i) / factorial(i);

  float finalValue = pow(x, n) + val;

  printf("%f\n", finalValue);

  return 0;
}