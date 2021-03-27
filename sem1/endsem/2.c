#include <stdio.h>

int isCapital(char chr)
{
  if (chr >= 'A' && chr <= 'Z')
    return 1;

  return 0;
}

void main()
{
  char str[100];

  // Input
  printf("Enter the string: ");
  scanf("%s", str);

  int m = 0, n = 0;

  for (int i = 0; i < 100 && str[i] != '\0'; i++)
  {
    if (isCapital(str[i]))
      m++;
    else
      n++;
  }

  float num = (3 * m - 2 * n) * 1.0 / 2;

  printf("Answer: %f\n", num);
}