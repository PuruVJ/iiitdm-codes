#include <stdio.h>

int sign(int i)
{
  if (i % 2 == 0)
    return 1.0;

  return -1.0;
}

float calculatePi()
{
  // Let's calculate value of PI
  /**
   * Using formula pi = 4 (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 ...)
   * For high accuracy, loop for 1000000 times
   */
  float val = 0;
  int i;
  for (i = 0; i < 1000000; i++)
  {
    val += 4 * sign(i) * 1.0 / (2 * i + 1);

    if (i < 4)
      printf("Iteration #%d: %f\n", i + 1, val);
  }

  return val;
}

// Let's find the value of Pi!!
void main()
{
  printf("\n%.6f\n", calculatePi());
}