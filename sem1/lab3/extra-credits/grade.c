#include <stdio.h>

int main()
{
  // Input variables
  int marks;

  printf("Enter marks: ");
  scanf("%d", &marks);

  // We don't need to specify the upper limit (marks < 100), as the flow of this if else statements
  // automatically eliminates the need for it
  if (marks >= 90)
  {
    printf("S\n");
  }
  else if (marks >= 80)
  {
    printf("A\n");
  }
  else if (marks >= 70)
  {
    printf("B\n");
  }
  else if (marks >= 60)
  {
    printf("C\n");
  }
  else if (marks >= 50)
  {
    printf("D\n");
  }
  else if (marks >= 40)
  {
    printf("E\n");
  }
  else
  {
    printf("F\n");
  }

  return 0;
}