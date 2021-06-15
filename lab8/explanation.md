# Q1

```cpp
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum = 0;
int n = 0;
int mean = 0;

int* numbers;
int numbersIndex = 0;

typedef struct _Node {
  int data;

  struct _Node* left;
  struct _Node* right;
} Node;

Node* newNode(int data) {
  Node* node = malloc(sizeof(Node));

  if (node == NULL) {
    printf("Insufficient Memory. Exiting program");
    exit(0);
  }

  node->data = data;

  node->left = NULL;
  node->right = NULL;

  return node;
}

Node* createTree(Node* root, int height) {
  Node* temp = root;

  root = newNode(rand() % 100);
  root->left = newNode(rand() % 100);
  root->right = newNode(rand() % 100);

  temp = root->left;
  root->left = temp;

  for (int i = 1; i < height; i++) {
    temp->data = rand() % 100;

    temp->left = newNode(rand() % 100);
    temp->right = newNode(rand() % 100);

    temp = temp->left;
  }

  return root;
}

void printPostOrder(Node* node) {
  if (node == NULL) return;

  // First on left
  printPostOrder(node->left);

  // Then right
  printPostOrder(node->right);

  // Now print present node
  printf("%d ", node->data);

  sum += node->data;
  *(numbers + numbersIndex) = node->data;
  n++, numbersIndex++;
}

void printInOrder(Node* node) {
  if (node == NULL) return;

  // Left
  printInOrder(node->left);

  // Print (left)
  printf("%d ", node->data);

  // Right
  printInOrder(node->right);
}

void printPreOrder(Node* node) {
  if (node == NULL) return;

  // Print current node (root)
  printf("%d ", node->data);

  // left
  printPreOrder(node->left);

  // Right
  printPreOrder(node->right);
}

float stdDeviation() {
  float nominator = 0;

  for (int i = 0; i < n; i++) nominator += pow(*(numbers + i) - mean, 2);

  return pow(nominator / n, 0.5);
}

void main() {
  int height;

  do {
    printf("Enter the height of tree (>= 3): ");
    scanf("%d", &height);

    if (height < 3) printf("\nHeight should be >= 3\n\n");

  } while (height < 3);

  numbers = calloc(pow(2, height) - 1, sizeof(int));

  srand(time(NULL));

  Node* root;
  root = createTree(root, height);

  printf("Preorder: ");
  printPreOrder(root);
  printf("\n");

  printf("Inorder: ");
  printInOrder(root);
  printf("\n");

  printf("PostOrder: ");
  printPostOrder(root);
  printf("\n");

  // Now calculate mean and std deviation
  float mean = sum * 1.0 / n;

  printf("Mean: %.2f\n", mean);
  printf("Std Deviation: %.2f\n", stdDeviation());

  free(numbers);
}
```

Let's start with `main` function.

We declare height variable, to take input of height from the user, then we take the input from user using a `do while` loop. Not required, just scanf is enough. You could've made the tree manually, so in that case, this step isn't required.

we're going to store the random numbers generated in the numbers pointer, so we declare it to the max size of `2^height - 1`, which is the maximum number of nodes a binary tree can have.

We declare root pointer (`Node * root;`), and run `createTree` function which returns the root pointer full of references to the whole tree. (More on that below)

Then we order our tree in the way we're requires to: `inorder`, `preorder` and `postorder`. More on these functions later.

Finally, we calculate the mean. We have global variables `sum` and `n` declared to which we add the required values in one of the tree printing functions(`postOrder` in this case).

## createTree

```cpp
Node* createTree(Node* root, int height) {
  Node* temp = root;

  root = newNode(rand() % 100);
  root->left = newNode(rand() % 100);
  root->right = newNode(rand() % 100);

  temp = root->left;
  root->left = temp;

  for (int i = 1; i < height; i++) {
    temp->data = rand() % 100;

    temp->left = newNode(rand() % 100);
    temp->right = newNode(rand() % 100);

    temp = temp->left;
  }

  return root;
}
```

Here, we take the `root` pointer. Due to the design of our program, root pointer is currently empty. So the first thing we do is fill it in. We assign root a pointer value, and populate its `left` and `right` pointer references too

```txt
      (random number) *root
      /                   \
     /                     \
(random number) *left    (random number) *right
```

When that is done, we iterate over the height of tree given, and create pointers on temp, its left and right, and set temp's address to point to its left. This will cause our tree to be inclined on the left

```txt
            [num]
           /     \
          [num]   [num]
         /    \
        [num]  [num]
       /     \
      [num]   [num]
     /
    [num]

```

## `printPostOrder`

```cpp
void printPostOrder(Node* node) {
  if (node == NULL) return;

  // First on left
  printPostOrder(node->left);

  // Then right
  printPostOrder(node->right);

  // Now print present node
  printf("%d ", node->data);

  sum += node->data;
  *(numbers + numbersIndex) = node->data;
  n++, numbersIndex++;
}
```

We use recursion to loop through the tree. Because this is postorder, we recursively go over left and right trees first before printing the current node's value.

We also populate our global variables `sum`, `numbers`, `n`,  and `numbersIndex` here to gather data to calculate mean and standard deviation.

## `inorder` and `preOrder`

```cpp
void printInOrder(Node* node) {
  if (node == NULL) return;

  // Left
  printInOrder(node->left);

  // Print (left)
  printf("%d ", node->data);

  // Right
  printInOrder(node->right);
}

void printPreOrder(Node* node) {
  if (node == NULL) return;

  // Print current node (root)
  printf("%d ", node->data);

  // left
  printPreOrder(node->left);

  // Right
  printPreOrder(node->right);
}
```

These function are simply for traversing the tree and printing it out. We don't need to touch the global variables here.

