/**
 * nCr = n! / ((n - r)!r!)
 * it can be re-arranged in the form: n/r * (n-1)/(r-1) * (n-2)/(r-2) * ... * (n - r - 1) / 1
 * 5C2 = 5/2 * 4/1
 * 6C3 = 6/3 * 5/2 * 4/1
 */

#include <stdio.h>

int nCr(int n, int r)
{
  if (r == 0)
    return 1;

  if (r == 1)
    return n;

  return (n * 1.0 / r) * nCr(n - 1, r - 1);
}

void main()
{
  int n, r;

  printf("Enter n: ");
  scanf("%d", &n);

  printf("Enter r: ");
  scanf("%d", &r);

  printf("%dC%d is: %d\n", n, r, nCr(n, r));
}