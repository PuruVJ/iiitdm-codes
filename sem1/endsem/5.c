#include <stdio.h>

int isPrime(int n)
{
  for (int i = 2; i <= n - 1; i++)
    if (n % i == 0)
      return 0;

  return 1;
}

void main()
{
  int n;

  printf("number of elemnts to be entered: ");
  scanf("%d", &n);

  int numbers[n];

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &numbers[i]);

  int sum = 0, numPrimeEls = 0;

  for (int i = 0; i < n; i++)
    if (i >= 2 && isPrime(i))
    {
      sum += numbers[i];
      numPrimeEls++;
    }

  printf("%f", sum * 1.0 / numPrimeEls);
}