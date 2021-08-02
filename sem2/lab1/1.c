#include <stdio.h>

void main()
{
  // (Input) Array size
  int n;

  printf("Enter size of Array: ");
  scanf("%d", &n);

  int numbers[n];

  printf("Enter %d element: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &numbers[i]);

  // Do the sum
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += numbers[i];

  printf("Sum of these numbers: %d\n", sum);
}
