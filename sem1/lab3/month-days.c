#include <stdio.h>

int main()
{
  // Input variables
  int monthNum;

  // Take the input
  printf("Input the number of the month: ");
  scanf("%d", &monthNum);

  int numDaysInMonth;

  switch (monthNum)
  {
  case 1:
    numDaysInMonth = 31;
    break;

  case 2:
    // Assuming it's a non-leap year
    numDaysInMonth = 27;
    break;

  case 3:
    numDaysInMonth = 31;
    break;

  case 4:
    numDaysInMonth = 30;
    break;

  case 5:
    numDaysInMonth = 31;
    break;

  case 6:
    numDaysInMonth = 30;
    break;

  case 7:
  case 8:
    numDaysInMonth = 31;
    break;

  case 9:
    numDaysInMonth = 30;
    break;

  case 10:
    numDaysInMonth = 31;
    break;

  case 11:
    numDaysInMonth = 30;
    break;

  case 12:
    numDaysInMonth = 31;
    break;

  default:
    printf("The month number should be between 1 nd 12 \n");
    return 0;
  }

  printf("Number of days in this month is: %d\n", numDaysInMonth);

  return 0;
}