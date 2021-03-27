#include <stdio.h>

int getPriceByCode(int code)
{
  int price;

  switch (code)
  {
  case 1:
    price = 20;
    break;
  case 2:
    price = 30;
    break;
  case 3:
    price = 20;
    break;
  case 4:
    price = 40;
    break;
  case 5:
    price = 150;
    break;
  case 6:
    price = 80;
    break;
  case 7:
    price = 10;
    break;
  case 8:
    price = 8;
    break;
  default:
    price = 0;
    break;
  }

  return price;
}

/** This function prints the menu */
void printMenu()
{
  // Column headers
  printf("Item");
  printf("           ");
  printf("Code");
  printf("            ");
  printf("Price");
  printf("\n");

  // Now print the contents
  printf("Pancake");
  printf("         ");
  printf("1");
  printf("                ");
  printf("%d", getPriceByCode(1));
  printf("\n");

  printf("Waffle");
  printf("          ");
  printf("2");
  printf("                ");
  printf("%d", getPriceByCode(2));
  printf("\n");

  printf("Nachos");
  printf("          ");
  printf("3");
  printf("                ");
  printf("%d", getPriceByCode(3));
  printf("\n");

  printf("Sandwich");
  printf("        ");
  printf("4");
  printf("                ");
  printf("%d", getPriceByCode(4));
  printf("\n");

  printf("Pizza");
  printf("           ");
  printf("5");
  printf("                ");
  printf("%d", getPriceByCode(5));
  printf("\n");

  printf("Burger");
  printf("          ");
  printf("6");
  printf("                ");
  printf("%d", getPriceByCode(6));
  printf("\n");

  printf("Chai");
  printf("            ");
  printf("7");
  printf("                ");
  printf("%d", getPriceByCode(7));
  printf("\n");

  printf("Water");
  printf("           ");
  printf("8");
  printf("                ");
  printf("%d", getPriceByCode(8));
  printf("\n");
}

void main()
{
  // Present the menu
  printMenu();

  // Print instructions
  printf("Please enter the code of the item you want, press ENTER key, then enter the quantity in next input \n");
  printf("Enter 0 when you wish to stop, and your total bill will be calculated \n");

  printf("\n\n");

  // Quantities go into this array
  int quantitiesEntered[8];

  // Initialize values
  int j;
  for (j = 0; j < 8; j++)
    quantitiesEntered[j] = 0;

  // Take input
  int code, quantity;

  while (1)
  {
    // Take code
    printf("Enter item code: ");
    scanf("%d", &code);

    if (code == 0)
      break;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    quantitiesEntered[code - 1] = quantity;
  }

  // Now calculate sum
  int sum = 0;

  int i;
  for (i = 0; i < 8; i++)
    sum += getPriceByCode(i + 1) * quantitiesEntered[i];

  printf("%d\n", sum);
}