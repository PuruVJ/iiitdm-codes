#include <stdio.h>
#include <string.h>
int main()
{
  //char actual_password[32] = "uufoETH{3_@l_`|vaX$^Amg#y}";
  char actual_password[32] = "uufoETH{hlaf7^1^@l_`|vaY$_Ang#y}";

  char password[32];
  int len = 32;
  printf("enter the password : ");
  scanf("%s", password);

  char *p = password;
  char *q = password;

  printf("%c\n", *p + 2);

  for (int i = 0; i < 10; i = i + 2)
  {
    *(p + i) = *(p + i) - 2;
  }
  p = p + 11;
  for (int i = 0; i <= 10; i = i + 2)
  {
    *(p + i) = *(p + i) + 1;
  }
  for (int i = 0; i < len; i = i + 1)
  {
    printf("%c", *(password + i));
  }

  if (strcmp(password, actual_password) == 0)
    printf("\nAccess Granted!\n");
  else
    printf("\nDenied!\n");
  return 0;
}