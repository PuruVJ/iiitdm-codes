/**
 * The formula is something like this:
 * = Math.floor(n / 5) + Math.floor(n / 25) + Math.floor(n / 125) + ... + 0
 */

#include <stdio.h>

int calcTrailingZeroesForLoop(int n)
{
  int num = 0;
  for (; n > 0;)
  {
    n /= 5;
    num += n;
  }

  return num;
}

int calcTrailingZeroesWhileLoop(int n)
{
  int num = 0;

  while (n > 0)
  {
    n /= 5;
    num += n;
  }

  return num;
}

int calcTrailingZeroesRecursion(int n)
{
  if (n == 0)
    return 0;

  return (n / 5) + calcTrailingZeroesRecursion(n / 5);
}

void main()
{
  // Input variable
  int n;

  printf("Enter the number: ");
  scanf("%d", &n);

  if (n < 0)
  {
    printf("Number should not be negative \n");
    return;
  }

  printf("[FOR LOOP] Number of trailing zeroes: %d \n", calcTrailingZeroesForLoop(n));
  printf("[WHILE LOOP] Number of trailing zeroes: %d \n", calcTrailingZeroesWhileLoop(n));
  printf("[RECURSION] Number of trailing zeroes: %d \n", calcTrailingZeroesRecursion(n));
}