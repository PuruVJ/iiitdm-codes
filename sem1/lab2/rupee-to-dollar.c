#include <stdio.h>

int main()
{
  // Input variables
  float amountInRupees;

  float conversionRate, resultInDollars;

  // Rate on 22 Dec, 2020
  conversionRate = 73.85;

  // Get the input
  printf("Enter amount in Rupee: ");
  scanf("%f", &amountInRupees);

  resultInDollars = amountInRupees / conversionRate;

  printf("Amount in Dollar: %f \n", resultInDollars);

  return 0;
}