#include <stdio.h>
#include <math.h>

int main()
{
  int x;
  x = -1 * pow(2, 30);

  printf("%d\n", x);

  x = x * 100;

  printf("The new x: %d\n", x);

  return 0;
}