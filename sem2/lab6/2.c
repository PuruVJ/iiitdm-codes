#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackItem {
  char str;
  struct StackItem* next;
} StackItem;

// Now work on making a stack
StackItem* top = NULL;

void push(char val) {
  StackItem* temp;

  temp = (StackItem*)malloc(sizeof(StackItem));
  temp->str = val;
  temp->next = top;

  top = temp;
}

char pop() {
  StackItem* temp;

  if (top == NULL) return '\0';

  char val;
  val = top->str;

  temp = top;
  top = top->next;

  free(temp);

  return val;
}

char VOWELS[5] = "aeiou";

bool isVowel(char val) {
  for (int i = 0; i < 5; i++)
    if (VOWELS[i] == val) return true;

  return false;
}

void main() {
  char* str = malloc(sizeof(char) * 100);
  printf("Enter the string: ");
  scanf("%s", str);

  for (int i = 0; i < strlen(str); i++) {
    char curChar = *(str + i);

    if (isVowel(curChar))
      pop();
    else
      push(curChar);

    if (top == NULL) continue;

    printf("%c ", top->str);
  }
  printf("\n");

  free(str);
}