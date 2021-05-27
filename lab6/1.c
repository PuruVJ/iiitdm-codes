#include <stdio.h>
#include <stdlib.h>

typedef struct StackItem {
  int number;
  struct StackItem* next;
} StackItem;

// Now work on making a stack
StackItem* top;

void push(int val) {
  StackItem* temp;

  temp = malloc(sizeof(StackItem));
  temp->number = val;
  temp->next = top;

  top = temp;
}

int pop() {
  StackItem* temp;

  if (top == NULL) return 0;

  int val;
  val = top->number;

  temp = top;
  top = top->next;

  free(temp);

  return val;
}

StackItem* createFactorialStack(int n) {
  for (int i = 1; i <= n; i++) push(i);
}

int calcFactorial() {
  int val = 1;

  while (1) {
    int temp = pop();
    if (!temp) break;

    val *= temp;
  }

  return val;
}

void main() {
  int n;

  printf("Enter value of n: ");
  scanf("%d", &n);

  // Preserve memory by returning early in case its 0
  if (n == 0) {
    printf("0! is 1\n");
    return;
  }

  createFactorialStack(n);

  printf("\n%d! is %d \n", n, calcFactorial(top));
}