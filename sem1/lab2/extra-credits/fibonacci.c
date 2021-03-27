#include <stdio.h>
#include <math.h>

// Calculate fibonacci without loops
// Fibonacci formula: (Phi^n - (-1/Phi)^n)/sqrt(5)

int main()
{
  // Input variable
  int n;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  // Value of Phi
  double phi = (sqrt(5) + 1.0) / 2;

  int value = (pow(phi, n) - pow((-1.0 / phi), n)) / sqrt(5);

  printf("%dth fibonacci number is: %d \n", n, value);

  return 0;
}