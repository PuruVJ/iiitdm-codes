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
  int temp = a + b;

  // Now swap
  a = temp - a;
  b = temp - b;

  printf("Swapped Pair is %d, %d \n", a, b);

  return 0;
}