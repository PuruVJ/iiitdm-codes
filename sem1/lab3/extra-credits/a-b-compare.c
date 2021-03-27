#include <stdio.h>

int main()
{
  // Input vars
  int a, b;

  // Take input
  printf("Enter first number, a: ");
  scanf("%d", &a);

  printf("Enter first number, b: ");
  scanf("%d", &b);

  if (a == b)
  {
    printf("Equal\n");
  }
  else if (a > b)
  {
    printf("Greater\n");
  }
  else
  {
    printf("Less\n");
  }

  return 0;
}