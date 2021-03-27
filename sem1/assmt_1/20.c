#include <stdio.h>

int isNegative(int num)
{
  if (num > 0)
    return 0;

  return 1;
}

void printInverseBinary(int binaryList[32])
{
  int i;
  for (i = 31; i >= 0; i--)
    printf("%d", binaryList[i]);

  printf("\n");
}

int invertBinDigit(int digit)
{
  if (digit == 0)
    return 1;

  return 0;
}

// This will check if any carry forwards are remaining
int binaryHasCarry(int binaryList[32])
{
  for (int i = 0; i < 32; i++)
    if (binaryList[i] == 2)
      return 1;

  return 0;
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

  int decimalIsNegative = 0;

  if (isNegative(decimal))
  {
    decimalIsNegative = 1;
    decimal = -decimal;
  }

  int remainder;
  // Loop through
  for (i = 0; i < 32; i++)
  {
    remainder = decimal % 2;

    binaryList[i] = remainder;

    decimal /= 2;
  }

  // Now we have the binary numbers
  // Let's invert those if needed
  if (!decimalIsNegative)
  {
    printInverseBinary(binaryList);
    return;
  }

  // Now invert now, as we have ruled out the possibility of the number being negative
  for (i = 0; i < 32; i++)
    binaryList[i] = invertBinDigit(binaryList[i]);

  binaryList[0] += 1;
  // Now add a unit digit to the end
  while (binaryHasCarry(binaryList))
    for (i = 0; i < 32; i++)
      if (binaryList[i] == 2)
      {
        binaryList[i] = 0;
        binaryList[i + 1] += 1;
      }

  printInverseBinary(binaryList);
}