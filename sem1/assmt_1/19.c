#include <stdio.h>

int isNegative(int num)
{
  if (num > 0)
    return 0;

  return 1;
}

void main()
{
  // Input vars
  int decimal;

  printf("Enter number in decimal form: ");
  scanf("%d", &decimal);

  // Array to store binary number
  int binaryList[32];

  // Initialize
  int i;
  for (i = 0; i < 32; i++)
    binaryList[i] = 0;

  if (isNegative(decimal))
  {
    binaryList[31] = 1;
    decimal = -decimal;
  }

  int remainder;
  // Loop through
  for (i = 0; i < 31; i++)
  {
    remainder = decimal % 2;

    binaryList[i] = remainder;

    decimal /= 2;
  }

  for (i = 31; i >= 0; i--)
    printf("%d", binaryList[i]);

  printf("\n");
}