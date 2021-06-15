#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node* left;
  struct node* right;
} Node;

typedef struct queue {
  struct node* loc;
  struct queue* next;
} Queue;

Queue* front = NULL;
Queue* rear = NULL;

void enqueue(Node* node) {
  Queue* temp = malloc(sizeof(Queue));

  temp->loc = node;

  if (front == NULL) {
    rear = front = temp;  // entering the data at rear end
    temp->next = NULL;
    return;
  }

  rear->next = temp;
  rear = temp;
  rear->next = NULL;
}

Node* dequeue() {
  if (front == NULL) {
    printf("underflow");
    exit(0);
  }

  Node* temp = malloc(sizeof(Node));  // deleting the front data
  temp = front->loc;
  front = front->next;
  return temp;
}

Node* create(Node* node) {
  int i = 0;

  Node* root = node;
  node->data = 65 + i;

  ++i;

  enqueue(node);

  while (i < 26) {
    node = dequeue();
    node->left = NULL;
    node->right = NULL;

    Node* temp1 = malloc(sizeof(Node));  // creating the binary tree and queue

    node->left = temp1;
    node->left->data = 65 + i;

    ++i;

    enqueue(node->left);

    if (i < 26) {
      Node* temp2 = malloc(sizeof(Node));
      node->right = temp2;
      node->right->data = 65 + i;

      ++i;

      enqueue(node->right);
    }
  }
  return (root);
}

void preorder(struct node* root) {
  if (root == 0) return;

  printf(" %c ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(struct node* root) {
  if (root == 0) return;

  inorder(root->left);
  printf(" %c ", root->data);

  inorder(root->right);
}

void postorder(struct node* root) {
  if (root == 0) return;

  postorder(root->left);
  postorder(root->right);
  printf(" %c ", root->data);
}

int main() {
  Node* root = malloc(sizeof(Node));
  root = create(root);

  printf("preorder data\n");
  preorder(root);

  printf("\nin order data\n");
  inorder(root);

  printf("\npost order data\n");
  postorder(root);

  printf("\n");
}