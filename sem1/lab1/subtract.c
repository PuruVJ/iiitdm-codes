#include <stdio.h>

int main()
{
  int a, b;

  printf("Enter value of a: ");
  scanf("%d", &a);

  printf("Enter value of b: ");
  scanf("%d", &b);

  int result = a - b;

  printf("The result is %d\n", result);

  return 0;
}