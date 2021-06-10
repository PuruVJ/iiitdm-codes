#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

#define MAX 10
int queue[MAX];

void enqueue(int val) {
  if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = val;
    return;
  }

  if ((rear + 1) % MAX == front) {
    printf("Overflow: Queue full!\n");
    return;
  }

  rear = (rear + 1) % MAX;
  queue[rear] = val;
}

void dequeue() {
  if (front == -1 && rear == -1) {
    printf("Undeflow: Queue empty\n");
    return;
  }

  if (front == rear) {
    printf("Dequeued element: %d \n", queue[front]);
    front = rear = -1;
    return;
  }

  printf("Dequeued element: %d \n", queue[front]);
  front = (front + 1) % MAX;
}

void display() {
  if (front == -1 && rear == -1) {
    printf("Queue is empty\n");
    return;
  }

  printf("\nElements in a Queue are :");

  for (int i = front; i <= rear; i = (i + 1) % MAX) printf(" %d ", queue[i]);

  printf("\n");
}

void main() {
  /** By default the choice is to insert element */
  int choice = 1, val;

  printf("\nPress 1: Insert an element");
  printf("\nPress 2: Delete an element");
  printf("\nPress 3: Display the elements\n");

  while (choice < 4 && choice != 0) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("Enter the element which is to be inserted: ");
      scanf("%d", &val);
      enqueue(val);
    }

    if (choice == 2) dequeue();

    if (choice == 3) display();
  }
}