/*
save the file as <roll_no.c>. Replace <roll_no> with your roll_no.
Once the coding part is complete, please upload the .c file in the google form:
https://forms.gle/hXdup8ZGftcjLhbC6

Name: Puru Vijayvargia
Roll No.: CS20B1078
Problem: Find the sum of the elements in the Left sub-tree using recursion.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
  int data;

  struct _TreeNode* left;
  struct _TreeNode* right;
} TreeNode;

TreeNode* node(int data) {
  TreeNode* node = malloc(sizeof(TreeNode));

  if (node == NULL) {
    printf("Insufficient Memory. Exiting program");
    exit(0);
  }

  node->data = data;

  node->left = NULL;
  node->right = NULL;

  return node;
}

int sumOfLeftSubTree(TreeNode* root) {
  if (root == NULL) return 0;

  int sum = root->data;
  sum += sumOfLeftSubTree(root->left);
  sum += sumOfLeftSubTree(root->right);

  return sum;
}

void main() {
  TreeNode* root;
  root = node(7);

  root->left = node(3);
  root->right = node(0);

  root->left->left = node(6);
  root->left->right = node(5);

  root->right->left = node(8);
  root->right->right = node(14);

  root->left->left->left = node(10);

  root->left->right->left = node(1);

  root->right->right->right = node(2);

  int sum = sumOfLeftSubTree(root->left);

  printf("\nThe sum of elements in left subtree is %d\n", sum);
}