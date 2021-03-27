/**
 * There was some confusion about what to do in this question, so I'll write out what I'm gonna do
 * Take input of **2** integers, compare sum of first one's digits to 2nd
 */

#include <stdio.h>

// Find the sum of the digits of a number
int sumOfDigits(int n)
{
  int sum = 0;

  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

void main()
{
  // Input vars
  int numWhoseDigitsToBeSummed, comparedNum;

  printf("Enter number whose digits to be summed: ");
  scanf("%d", &numWhoseDigitsToBeSummed);

  printf("Enter number with whom to compare: ");
  scanf("%d", &comparedNum);

  int sum = sumOfDigits(numWhoseDigitsToBeSummed);

  if (sum == comparedNum)
  {
    printf("Sum of first number == Second number");
  }
  else
  {
    printf("Sum of first number != Second number");
  }
}