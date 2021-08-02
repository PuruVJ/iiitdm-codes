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

# Q2

```cpp
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

    if (isVowel(curChar)) {
      pop();
    } else {
      push(curChar);
    }

    if (top == NULL) continue;

    printf("%c ", top->str);
  }
  printf("\n");

  free(str);
}
```

Let's start from `main`.

First we declare the empty char pointer variable `str`, and initialise memory of size 100 bytes to hold 100 characters. **This step is important, as we can't scanf to an empty pointer. Some memory must be give too it**.

We `scanf` the string to thsi variable.

After that, we got a loop parsing over every single character entered in the string. We use `strlen` function from `string.h` header file to get the length, and use it as `n` for our loop.

```cpp
for (int i = 0; i < strlen(str); i++) {
  char curChar = *(str + i);

  if (isVowel(curChar)) {
    pop();
  } else {
    push(curChar);
  }

  if (top == NULL) continue;

  printf("%c ", top->str);
}
```

Next up, get current charcter, then run it throught the `isVowel` function. 

This function simply loops over and checks if the character is a boolean or not. Rather than the traditional method of returning  `1` for `true` and `0` for `false`, I use the `bool` data type from the `stdbool.h` header file to allow use of `true` and `false` in the program. These are exactly same as `1` or `0`

If we get `true`, `pop` the stack, as stated in the question, so teh consonant before gets removed, if it was there in the first place. Otherwise nothing happens if stack was empty and the program moves on to next character.

Otherwise, if it is a consonant, we push the consonant to the stack and move on.

Then we try to print the value in the  `top` of the stack, but because it might be empty, accessing it may break the program. So we check if it is `NULL`. If it is, we simply move on to next character without printing. Otherwise, print the character and move on.

Finally, we `free` the `str` char* variable we declared.

## Some functions

### `isVowel`

```cpp
char VOWELS[5] = "aeiou";

bool isVowel(char val) {
  for (int i = 0; i < 5; i++)
    if (VOWELS[i] == val) return true;

  return false;
}
```

Notice that we have a globally available array here, `VOWELS`. This array could easily have been inside the `isVowel` function, as it is only used there.

`isVowel` simply loops over the array, checking each character in it to the `val` character we passed as a parameter. if it find it, the funtion stops and returns `true`. Otherwise, it returns `false` after the loop finishes.

### `pop`

```cpp
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
```

Again, our `pop` isn't a **Standard** `pop`, it is made for this program specifically. it tries to free the memory and all, but the critical condition here is: If `top` is empty, it return `\0`, which is an empty string character/endline charcter and stops. It doesn't give error, it simply doesn't do anything after

Rest fo it is pretty standard. Stores the value to be popped, set a `temp` pointer  to `top`, sets `top` to its `top->next`, then deletes `temp` and returns the value