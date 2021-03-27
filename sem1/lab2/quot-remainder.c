#include <stdio.h>

int main()
{
  // Inputs
  int numerator, denominator;

  // Input numerator
  printf("Enter numerator: ");
  scanf("%d", &numerator);

  // Input denominator
  printf("Enter denominator: ");
  scanf("%d", &denominator);

  int quotient = numerator / denominator;

  float remainder = numerator % denominator;

  // Print results
  printf("Quotient: %d\n", quotient);
  printf("Remainder %f\n", remainder);

  return 0;
}