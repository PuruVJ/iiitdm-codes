#include <stdio.h>

struct Mobile
{
  char name[100];
  char model[100];
  int price;
};

int sum_mobiles(int price, int *sum)
{
  *sum += price;
}

void main()
{
  int n;

  printf("number of phones to enter: ");
  scanf("%d", &n);

  struct Mobile mobiles[n];

  int *sum = 0;

  for (int i = 0; i < n; i++)
  {
    printf("\n");

    printf("Mobile Name: ");
    scanf("%s", mobiles[i].name);

    printf("Model Number: ");
    scanf("%s", mobiles[i].model);

    printf("Price: ");
    scanf("%d", &mobiles[i].price);

    sum_mobiles(mobiles[i].price, sum);
  }

  printf("\nSum of all mobiles: %d", *sum);

  return;
}
