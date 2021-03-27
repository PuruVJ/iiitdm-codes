#include <stdio.h>
#include <math.h>

int decToBin(int n)
{
  int binary = 0;

  for (int i = 0; n > 0; i++, n /= 2)
    binary += n % 2 * pow(10, i);

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