#include <stdio.h>
#include <math.h>

int main()
{
  int x;
  x = pow(2, 30);

  printf("%d\n", x);

  x = x * 10;

  printf("The new x: %d\n", x);

  return 0;
}