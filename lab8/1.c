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