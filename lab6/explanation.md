# Code 1

```cpp
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

void createFactorialStack(int n) {
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
```

## Gist

We take input of `n` from user.

Then we check if n is 0, if it is, return 1 (0! = 1). This is to save memory and work for computer.

### Call `createFactorialStack`

This creates a stack with consecutive values, like ->

1->2->3->4->5->6->7....->n

> Note that these are added to the top of the stack, so the actual stack is in descending order.

```cpp
void createFactorialStack(int n) {
  for (int i = 1; i <= n; i++) push(i);
}
```

This is a one liner function, that simply pushes to the stack using a loop. This loop starts from 1 rather than 0 and goes to have values up to n, rather than n - 1.

It is equivalent to:

```cpp
void createFactorialStack(int n) {
  for (int i = 0; i < n; i++) push(i + 1);
}
```

This function creates the stack.

### Call `calcFactorial`

we call `calcFactorial` function with n. 

```cpp
int calcFactorial() {
  int val = 1;

  while (1) {
    int temp = pop();
    if (!temp) break;

    val *= temp;
  }

  return val;
}

```

In factorial calculations, we start from a variable with initial value `1`, because we multiply stuff to it.

Now, we have an infinite loop that keeps going until the stack is completely empty.

Inside it, we `pop` the stack, which returns the value removed, and check if it is 0 or not. generally returning 0 if value not found isn't a good pattern, but here because we only have posituve values here, we can safely assume 0 to mean the breaking point.

If we get a non-0 value, we move on, set `val` to `val * temp`, the number that was popped. Finally we return the value