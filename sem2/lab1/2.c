#include <stdio.h>
#include <string.h>

void main()
{
  char str[100];

  printf("Enter the string: ");
  scanf("%s", str);

  // Do the checking
  int start = 0;
  int end = strlen(str) - 1;

  while (start < end)
  {
    if (str[start] != str[end])
    {
      printf("Not a palindrome\n");
      return;
    }

    start++;
    end--;
  }
  printf("Its a palindrome\n");
}