#include <stdio.h>

int main()
{
  // Take the input
  int numPlayers;

  printf("Enter number of players: ");
  scanf("%d", &numPlayers);

  // Formula: nC2 = n * (n - 1) / 2 - n = n * (n - 3) / 2 (Pre-calculations)
  int numUniqueExchanges = numPlayers * (numPlayers - 3) / 2;

  printf("Total number of unique exchanges that can happen without simultaneous exchanges is: %d \n", numUniqueExchanges);

  return 0;
}