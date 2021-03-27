#include <stdio.h>

struct Book
{
  char name[100];
  int id;
  char author[100];
};

void printAuthor(int id, struct Book books[], int n)
{
  for (int i = 0; i < n; i++)
    if (books[i].id == id)
    {
      printf("Author %s\n", books[i].author);
      return;
    }

  printf("No author for that  ID \n");
}

void main()
{
  FILE *file;

  file = fopen("books.txt", "w+");

  // Input
  int n;

  printf("number of books: ");
  scanf("%d", &n);

  struct Book books[n];

  printf("Enter book details: ");
  for (int i = 0; i < n; i++)
  {
    printf("\n");

    printf("Enter Name of book: ");
    scanf("%s", books[i].name);

    printf("Enter ID of book: ");
    scanf("%d", &books[i].id);

    printf("Enter Author of book: ");
    scanf("%s", books[i].author);

    // Write to file
    fprintf(file, "%s %s %s", "Name:", books[i].name, "\n");
    fprintf(file, "%s %d %s", "ID:", books[i].id, "\n");
    fprintf(file, "%s %s %s", "Author:", books[i].author, "\n\n");
  }

  printf("\n");

  int inputBookID;

  printf("Enter author ID: ");
  scanf("%d", &inputBookID);

  printAuthor(inputBookID, books, n);
}