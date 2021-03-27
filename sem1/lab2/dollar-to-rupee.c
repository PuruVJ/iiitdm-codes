#include <stdio.h>

int main()
{
  // Input variables
  float amountInDollar;

  float conversionRate, resultInRupee;

  // Rate on 22 Dec, 2020
  conversionRate = 73.85;

  // Get the input
  printf("Enter amount in Dollar: ");
  scanf("%f", &amountInDollar);

  resultInRupee = amountInDollar * conversionRate;

  printf("Amount in Rupee: %f \n", resultInRupee);

  return 0;
}