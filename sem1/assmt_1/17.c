#include <stdio.h>

// Maximum gap in range
// RANGE = 10 during testing, 200 for final code
int RANGE = 10;

void main()
{
  int n;

  printf("Enter value of n: ");
  scanf("%d", &n);

  int expectedNumbers[RANGE + 1];

  int i;
  for (i = 0; i < RANGE + 1; i++)
  {
    expectedNumbers[i] = n + i;
  }

  // Now start taking inputs
  int curInput;

  int j;
  for (i = 0; i < RANGE; i++)
  {
    printf("Enter %dth number: ", i + 1);
    scanf("%d", &curInput);

    if (curInput < n || curInput > n + RANGE)
    {
      printf("Please enter values between %d and %d, both included. \n", n, n + RANGE);
      return;
    }

    for (j = 0; j < RANGE + 1; j++)
      if (expectedNumbers[j] == curInput)
      {
        expectedNumbers[j] = n - 1;
        break;
      }
  }

  // Now check the values
  for (i = 0; i < RANGE + 1; i++)
    if (expectedNumbers[i] != n - 1)
    {
      // This is the one
      printf("The missing number in the range is: %d\n", expectedNumbers[i]);
      return;
    }
}