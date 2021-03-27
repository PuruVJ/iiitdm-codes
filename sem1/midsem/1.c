#include <stdio.h>

void main()
{
  // Input number
  int n;

  printf("Enter the number: ");
  scanf("%d", &n);

  // Different sums
  int oddSum = 0, evenSum = 0;

  int digit;
  for (int i = 0; n > 0; i++, n /= 10)
  {
    digit = n % 10;

    if (digit % 2 == 0)
      evenSum += digit;
    else
      oddSum += digit;
  }

  float sum = (2.0 * oddSum + 3.0 * evenSum) / 5;

  printf("%f\n", sum);

  return 0;
}