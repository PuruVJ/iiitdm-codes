#include <stdio.h>

int main()
{
  // Input vars
  int year;

  printf("Enter the year to checked: ");
  scanf("%d", &year);

  if (year % 4 == 0)
  {
    printf("Leap year \n");
  }
  else
  {
    printf("Not a leap year \n");
  }

  return 0;
}