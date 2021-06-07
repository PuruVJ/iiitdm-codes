#include <stdio.h>
#include <stdlib.h>

typedef long long int llt;
typedef long long int type;

typedef struct Node {
  llt key;
  type data;
  struct Node* prev;
} Node;

typedef struct Stack {
  Node* Top;
  long long int size;

} Stack;

Node* top;

Node peek(Stack* stack) { return *stack->Top; }

void push(Stack* stack, type data) {
  Node* new_tray;

  new_tray = (Node*)malloc(sizeof(Node));
  if (new_tray == NULL) {
    printf("\nOut of Memory! Program Exit!\n");
    exit(0);
  }

  new_tray->data = data;
  new_tray->prev = stack->Top;

  stack->size++;

  new_tray->key = stack->size;
  stack->Top = new_tray;
}

void main() {
  Node a, b;

  a.data = 123;
  b.data = 111;

  b = a;

  printf("%lld %lld", a.data, b.data);

  a.data = 69;

  printf("%lld %lld", a.data, b.data);
}