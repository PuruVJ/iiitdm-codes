#include <stdio.h>

void main()
{
  int number;

  // Input
  printf("Enter the number: ");
  scanf("%d", &number);

  int count = 0;
  int n = number;

  while (n != 0)
  {
    n /= 10;
    count++;
  }

  int numberArray[count];

  count = 0;
  n = number;

  while (n != 0)
  {
    numberArray[count] = n % 10;
    n /= 10;
    count++;
  }

  for (int i = 0; i < count; i++)
  {
    printf("%d\n", numberArray[count - i - 1]);
  }
}