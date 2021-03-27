#include <stdio.h>

int main()
{
  // Input vars
  int a, b;

  printf("Enter first number: ");
  scanf("%d", &a);

  printf("Enter second number: ");
  scanf("%d", &b);

  // Middle variable
  a = a + b;

  // Now swap
  b = a - b;
  a = a - b;

  printf("Swapped Pair is %d, %d \n", a, b);

  return 0;
}