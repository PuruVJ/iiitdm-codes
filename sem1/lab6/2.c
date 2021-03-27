#include <stdio.h>
#include <math.h>

int decToBin(int n)
{
  int binary = 0;

  int remainder;

  int i = 0;
  while (n > 0)
  {
    remainder = n % 2;

    binary += remainder * pow(10, i);

    i++;

    // Change n
    n /= 2;
  }

  return binary;
}

void main()
{
  // Input
  int decimalNum;

  // Take input
  printf("Enter number: ");
  scanf("%d", &decimalNum);

  int binaryNum = decToBin(decimalNum);

  printf("Number in binary: %d \n", binaryNum);
}