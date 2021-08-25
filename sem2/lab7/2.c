#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  int number;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *Top;
} Stack;

typedef struct Queue {
  Node *front;
  Node *rear;
} Queue;

/** Core Functions defined here */
int stackSize = 0;

int queueSize;
int queueMaxSize;

void createStack(Stack *stack) {
  stack->Top = NULL;

  stackSize = 0;
}

void createQueue(Queue *queue, int max) {
  queue->front = NULL;
  queue->rear = NULL;

  queueMaxSize = max;
  queueSize = 0;
}

void freeStack(Stack *stack) {
  Node *temp;

  while (stack->Top != NULL) {
    temp = stack->Top->next;
    free(stack->Top);
    stack->Top = temp;
  }
}

void freeQueue(Queue *queue) {
  Node *temp;
  while (queue->front != NULL) {
    temp = queue->front;

    if (queue->front == queue->rear) queue->rear = NULL;

    queue->front = queue->front->next;

    free(temp);
  }
}

Node *peekStack(Stack *stack) {
  if (stackSize == 0) return NULL;

  return stack->Top;
}

Node *peekQueue(Queue *queue) {
  if (queueSize == 0) return NULL;

  return queue->front;
}

void push(Stack *stack, int data) {
  Node *temp = malloc(sizeof(Node));

  if (temp == NULL) {
    printf("\nOut of Memory! Program Exit!\n");
    freeStack(stack);
    exit(0);
  }

  temp->number = data;
  temp->next = stack->Top;

  stackSize++;

  temp->key = stackSize;
  stack->Top = temp;
}

int pop(Stack *stack) {
  Node *temp;

  if (stack->Top == NULL) {
    printf("\nUNDERFLOW! Program Exit!");
    exit(0);
  }

  int carID = stack->Top->number;

  temp = stack->Top;
  stack->Top = stack->Top->next;
  stackSize--;

  free(temp);

  return carID;
}

void enqueue(Queue *queue, int d) {
  Node *temp = malloc(sizeof(Node));

  if (temp == NULL) {
    printf("Insufficient Memory! Program Terminated!");
    freeQueue(queue);
    exit(0);
  }

  if (queueSize == queueMaxSize) {
    printf("Parking Lot FULL!");
    return;
  }

  temp->number = d;
  temp->next = NULL;

  queueSize = (queueSize) + 1;

  temp->key = queueSize;

  if (queue->rear == NULL) {
    queue->front = temp;
    queue->rear = temp;
  } else {
    queue->rear->next = temp;
    queue->rear = temp;
  }
}

int dequeue(Queue *queue) {
  Node *temp;

  if (queue->front == NULL) {
    printf("\nParking Lot is Empty!\n");
    return -1;
  }

  int carID;
  carID = queue->front->number;
  queueSize -= 1;
  temp = queue->front;

  if (queue->front == queue->rear) queue->rear = NULL;

  queue->front = queue->front->next;

  free(temp);

  return carID;
}

/** Parking lot related functions here */

void addCarToFront(Queue *queue, int k, int d) {
  Node *temp = malloc(sizeof(Node));

  if (temp == NULL) {
    printf("\nInsufficient Memory! Program Terminated!\n");
    freeQueue(queue);
    exit(0);
  }

  if (queueSize == queueMaxSize) {
    printf("\nParking Lot FULL!\n");
    return;
  }

  temp->key = k;
  temp->number = d;

  queueSize = (queueSize) + 1;

  if (queue->front == NULL) {
    temp->next = NULL;
    queue->front = temp;
    queue->rear = temp;
  } else {
    temp->next = queue->front;
    queue->front = temp;
  }
}

void removeCarFromQueue(Queue *queue, int k) {
  if (k > queueSize) {
    printf("Enter a number less than or equal to %d", queueSize);
    return;
  };

  Stack temp;

  createStack(&temp);

  k--;

  for (; k > 0; k--) push(&temp, dequeue(queue));

  dequeue(queue);
  printf("\nCar removed!!\n");

  int x;

  while (temp.Top != NULL) {
    x = temp.Top->key;
    addCarToFront(queue, x, pop(&temp));
  }
}

void printCarQueue(Queue *queue) {
  for (Node *ptr = queue->front; ptr != NULL; ptr = ptr->next)
    printf(" %d ", ptr->number);
}

void main() {
  Queue queue;

  int max;

  printf("Enter Max Size of Parking Lot : ");
  scanf("%d", &max);

  printf("\n\n");
  createQueue(&queue, max);

  int data;
  char choice = '1';
  int k;

  printf("Select one of the following :\n\n");
  printf("\n1. Press 'e' to enter a new car in the Parking from rear");
  printf(
      "\n2. Press 'l' to remove a new car from the Parking from the FRONT "
      "end.");
  printf("\n3. Press 's' to show the cars currently present in the Parking.");
  printf(
      "\n4. Press 'r' to Remove a car from a given Location (K) in the "
      "parking.");
  printf("\n5. Press 'q' to Quit.\n\n");

  while (!(choice == 'q' || choice == 'Q')) {
    printf("\nEnter Your Choice:- ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
      printf("\nEnter Car No: ");
      scanf(" %d", &data);
      enqueue(&queue, data);
    }

    if (choice == 'l' || choice == 'L')
      if (peekQueue(&queue) != NULL)
        printf("New Car : Car No %d", dequeue(&queue));

    if (choice == 's' || choice == 'S') printCarQueue(&queue);

    if (choice == 'r' || choice == 'R') {
      printf("\nEnter Car No to remove : ");
      scanf(" %d", &k);
      removeCarFromQueue(&queue, k);
    }
  }
}