#include <stdio.h>

int main()
{
  // Take the input
  int numPlayers;

  printf("Enter number of players: ");
  scanf("%d", &numPlayers);

  // Formula: nC2 = n * (n - 1) / 2
  int numUniqueExchanges = numPlayers * (numPlayers - 1) / 2;

  printf("Total number of unique exchanges that can happen is: %d \n", numUniqueExchanges);

  return 0;
}